#ifndef N64CRC
#define N64CRC

unsigned int crc, poly, seed = 0;
unsigned int crc_table[256] = {0};
unsigned int t1, t2, t3, t4, t5, t6 = 0;
unsigned int r, d = 0;
unsigned short cic = 0;

#endif // N64CRC
