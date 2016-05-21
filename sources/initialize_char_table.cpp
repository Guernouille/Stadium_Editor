#include "mainwindow.h"

void MainWindow::initialize_char_table()
{
    for (short i=0;i<256;i++){
        char_table[i] = "";
    }

    if(this->romtype == ENGLISH){
        char_table[0x00] = "";
        char_table[0x0A] = "\n";
        char_table[0x20] = " ";
        char_table[0x21] = "!";
        char_table[0x23] = "#";
        char_table[0x27] = "'";
        char_table[0x28] = "(";
        char_table[0x29] = ")";
        char_table[0x2A] = "*";
        char_table[0x2B] = "+";
        char_table[0x2C] = ",";
        char_table[0x2D] = "-";
        char_table[0x2E] = ".";
        char_table[0x2F] = "/";
        char_table[0x30] = "0";
        char_table[0x31] = "1";
        char_table[0x32] = "2";
        char_table[0x33] = "3";
        char_table[0x34] = "4";
        char_table[0x35] = "5";
        char_table[0x36] = "6";
        char_table[0x37] = "7";
        char_table[0x38] = "8";
        char_table[0x39] = "9";
        char_table[0x3A] = ":";
        char_table[0x3B] = ";";
        char_table[0x3D] = "=";
        char_table[0x3F] = "?";
        char_table[0x41] = "A";
        char_table[0x42] = "B";
        char_table[0x43] = "C";
        char_table[0x44] = "D";
        char_table[0x45] = "E";
        char_table[0x46] = "F";
        char_table[0x47] = "G";
        char_table[0x48] = "H";
        char_table[0x49] = "I";
        char_table[0x4A] = "J";
        char_table[0x4B] = "K";
        char_table[0x4C] = "L";
        char_table[0x4D] = "M";
        char_table[0x4E] = "N";
        char_table[0x4F] = "O";
        char_table[0x50] = "P";
        char_table[0x51] = "Q";
        char_table[0x52] = "R";
        char_table[0x53] = "S";
        char_table[0x54] = "T";
        char_table[0x55] = "U";
        char_table[0x56] = "V";
        char_table[0x57] = "W";
        char_table[0x58] = "X";
        char_table[0x59] = "Y";
        char_table[0x5A] = "Z";
        char_table[0x5B] = "[";
        char_table[0x5D] = "]";
        char_table[0x61] = "a";
        char_table[0x62] = "b";
        char_table[0x63] = "c";
        char_table[0x64] = "d";
        char_table[0x65] = "e";
        char_table[0x66] = "f";
        char_table[0x67] = "g";
        char_table[0x68] = "h";
        char_table[0x69] = "i";
        char_table[0x6A] = "j";
        char_table[0x6B] = "k";
        char_table[0x6C] = "l";
        char_table[0x6D] = "m";
        char_table[0x6E] = "n";
        char_table[0x6F] = "o";
        char_table[0x70] = "p";
        char_table[0x71] = "q";
        char_table[0x72] = "r";
        char_table[0x73] = "s";
        char_table[0x74] = "t";
        char_table[0x75] = "u";
        char_table[0x76] = "v";
        char_table[0x77] = "w";
        char_table[0x78] = "x";
        char_table[0x79] = "y";
        char_table[0x7A] = "z";
        char_table[0xA9] = "♂";
        char_table[0xBE] = "♀";
        char_table[0xE9] = "é";
    }
}

