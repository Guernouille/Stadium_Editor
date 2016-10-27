/*
 * N64 cartridge header CRC fix
 * Adapted from n64crc.c, available on n64dev.org
 *
 * Original version is (C) 2005 Parasyte, GNU General Public License
 * Based on uCON64's N64 checksum algorithm by Andreas Sterbenz
 */

#include "mainwindow.h"

#define ROL(i, b) (((i) << (b)) | ((i) >> (32 - (b))))

#define N64_HEADER_SIZE  0x40
#define N64_BC_SIZE      (0x1000 - N64_HEADER_SIZE)

#define CHECKSUM_START   0x00001000
#define CHECKSUM_LENGTH  0x00100000
#define CHECKSUM_CIC6102 0xF8CA4DDC
#define CHECKSUM_CIC6103 0xA3886759
#define CHECKSUM_CIC6105 0xDF26F436
#define CHECKSUM_CIC6106 0x1FEA617A

unsigned int crc_table[256];
unsigned int crc, poly, seed;
unsigned int t1, t2, t3, t4, t5, t6;
unsigned int r, d;
unsigned short cic;

void MainWindow::n64crc(QFile &romfile)
{
    QDataStream read(&romfile);

    poly = 0xEDB88320;

    for (short i=0; i<256; i++) {
        crc = i;
        for (short j=8; j>0; j--) {
            if (crc & 1) crc = (crc >> 1) ^ poly;
            else crc >>= 1;
        }
        crc_table[i] = crc;
    }

    crc = ~0;
    romfile.seek(N64_HEADER_SIZE);
    for(short i=0; i<N64_BC_SIZE; i++) {
        read>>buf8;
        crc = (crc >> 8) ^ crc_table[(crc ^ buf8) & 0xFF];
    }

    switch (~crc) {
        case 0x6170A4A1:
            cic = 6101;
            break;
        case 0x90BB6CB5:
            cic = 6102;
            break;
        case 0x0B050EE0:
            cic = 6103;
            break;
        case 0x98BC2C86:
            cic = 6105;
            break;
        case 0xACC8580A:
            cic = 6106;
            break;
        default:
            cic = 6105;
    }

    switch (cic) {
        case 6101:
        case 6102:
            seed = CHECKSUM_CIC6102;
            break;
        case 6103:
            seed = CHECKSUM_CIC6103;
            break;
        case 6105:
            seed = CHECKSUM_CIC6105;
            break;
        case 6106:
            seed = CHECKSUM_CIC6106;
            break;
        default:
            seed = 0;
            QMessageBox messageBox;
            messageBox.setText("Unable to calculate CRC.");
            messageBox.setWindowTitle("CRC calculation error");
            messageBox.exec();
    }
    t1 = t2 = t3 = t4 = t5 = t6 = seed;

    if(seed != 0){
        unsigned int i = CHECKSUM_START;

        while(i < (CHECKSUM_START + CHECKSUM_LENGTH)) {
            romfile.seek(CHECKSUM_START + i);
            read>>d;
            if ((t6 + d) < t6) t4++;
            t6 += d;
            t3 ^= d;
            r = ROL(d, (d & 0x1F));
            t5 += r;
            if (t2 > d) t2 ^= r;
            else t2 ^= t6 ^ d;

            if (cic == 6105) {
                romfile.seek(N64_HEADER_SIZE + 0x710 + (i & 0xFF));
                read>>buf32;
                t1 += buf32 ^ d;
            }
            else t1 += t5 ^ d;

            i += 4;
        }
        if (cic == 6103) {
            header_crc1 = (t6 ^ t4) + t3;
            header_crc2 = (t5 ^ t2) + t1;
        }
        else if (cic == 6106) {
            header_crc1 = (t6 * t4) + t3;
            header_crc2 = (t5 * t2) + t1;
        }
        else {
            header_crc1 = t6 ^ t4 ^ t3;
            header_crc2 = t5 ^ t2 ^ t1;
        }
    }
}
