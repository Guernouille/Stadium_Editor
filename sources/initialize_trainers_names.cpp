#include "mainwindow.h"

void MainWindow::initialize_trainers_names(){
    for(short i=0;i<256;i++) {
        for(short j=0;j<5;j++){
            preset_trainers_names[i][j]="ERROR";
        }
    }
    preset_trainers_names[0][0]="???";
    preset_trainers_names[0][1]="UNKNOWN";
    preset_trainers_names[0][2]="ANON";
    preset_trainers_names[0][3]="JohnDoe";
    preset_trainers_names[0][4]="Dr. Who";
    preset_trainers_names[1][0]="RED";
    preset_trainers_names[1][1]="BLUE";
    preset_trainers_names[1][2]="GREEN";
    preset_trainers_names[1][3]="YELLOW";
    preset_trainers_names[1][4]="TRAINER";
    preset_trainers_names[2][0]="BROCK";
    preset_trainers_names[2][1]="Broke";
    preset_trainers_names[2][2]="Stone";
    preset_trainers_names[2][3]="BROCK";
    preset_trainers_names[2][4]="BROCK";
    preset_trainers_names[3][0]="MISTY";
    preset_trainers_names[3][1]="MISTY";
    preset_trainers_names[3][2]="MISTY";
    preset_trainers_names[3][3]="MISTY";
    preset_trainers_names[3][4]="MISTY";
    preset_trainers_names[4][0]="SURGE";
    preset_trainers_names[4][1]="SURGERY";
    preset_trainers_names[4][2]="SURGE";
    preset_trainers_names[4][3]="SURGE";
    preset_trainers_names[4][4]="SURGE";
    preset_trainers_names[5][0]="ERIKA";
    preset_trainers_names[5][1]="ERIKA";
    preset_trainers_names[5][2]="ERIKA";
    preset_trainers_names[5][3]="ERIKA";
    preset_trainers_names[5][4]="ERIKA";
    preset_trainers_names[6][0]="KOGA";
    preset_trainers_names[6][1]="Ninja";
    preset_trainers_names[6][2]="KOGA";
    preset_trainers_names[6][3]="KOGA";
    preset_trainers_names[6][4]="KOGA";
    preset_trainers_names[7][0]="SABRINA";
    preset_trainers_names[7][1]="SABRINA";
    preset_trainers_names[7][2]="SABRINA";
    preset_trainers_names[7][3]="SABRINA";
    preset_trainers_names[7][4]="SABRINA";
    preset_trainers_names[8][0]="BLAINE";
    preset_trainers_names[8][1]="BLAINE";
    preset_trainers_names[8][2]="BLAINE";
    preset_trainers_names[8][3]="BLAINE";
    preset_trainers_names[8][4]="BLAINE";
    preset_trainers_names[9][0]="GIOVANI";
    preset_trainers_names[9][1]="GIOVANI";
    preset_trainers_names[9][2]="GIOVANI";
    preset_trainers_names[9][3]="GIOVANI";
    preset_trainers_names[9][4]="GIOVANI";
    preset_trainers_names[10][0]="LORELEI";
    preset_trainers_names[10][1]="LORELEI";
    preset_trainers_names[10][2]="LORELEI";
    preset_trainers_names[10][3]="LORELEI";
    preset_trainers_names[10][4]="LORELEI";
    preset_trainers_names[11][0]="BRUNO";
    preset_trainers_names[11][1]="PJSalt";
    preset_trainers_names[11][2]="BRUNO";
    preset_trainers_names[11][3]="BRUNO";
    preset_trainers_names[11][4]="BRUNO";
    preset_trainers_names[12][0]="AGATHA";
    preset_trainers_names[12][1]="OLD WOMAN";
    preset_trainers_names[12][2]="Christie";
    preset_trainers_names[12][3]="AGATHA";
    preset_trainers_names[12][4]="AGATHA";
    preset_trainers_names[13][0]="LANCE";
    preset_trainers_names[13][1]="Cheater";
    preset_trainers_names[13][2]="LANCE";
    preset_trainers_names[13][3]="LANCE";
    preset_trainers_names[13][4]="LANCE";
    preset_trainers_names[14][0]="RIVAL";
    preset_trainers_names[14][1]="BLUE";
    preset_trainers_names[14][2]="Douche";
    preset_trainers_names[14][3]="AAAAAAA";
    preset_trainers_names[14][4]="RIVAL";
    preset_trainers_names[15][0]="BUG BOY";
    preset_trainers_names[15][1]="Bug Report";
    preset_trainers_names[15][2]="BUG BOY";
    preset_trainers_names[15][3]="BUG BOY";
    preset_trainers_names[15][4]="BUG BOY";
    preset_trainers_names[16][0]="LASS";
    preset_trainers_names[16][1]="LASS";
    preset_trainers_names[16][2]="LASS";
    preset_trainers_names[16][3]="LASS";
    preset_trainers_names[16][4]="LASS";
    preset_trainers_names[17][0]="LAD";
    preset_trainers_names[17][1]="Shorts Kid";
    preset_trainers_names[17][2]="LAD";
    preset_trainers_names[17][3]="LAD";
    preset_trainers_names[17][4]="LAD";
    preset_trainers_names[18][0]="JR.♂";
    preset_trainers_names[18][1]="JR.♂";
    preset_trainers_names[18][2]="JR.♂";
    preset_trainers_names[18][3]="JR.♂";
    preset_trainers_names[18][4]="JR.♂";
    preset_trainers_names[19][0]="JR.♀";
    preset_trainers_names[19][1]="JR.♀";
    preset_trainers_names[19][2]="JR.♀";
    preset_trainers_names[19][3]="JR.♀";
    preset_trainers_names[19][4]="JR.♀";
    preset_trainers_names[20][0]="NERD";
    preset_trainers_names[20][1]="Speedrunnr";
    preset_trainers_names[20][2]="DisASMbler";
    preset_trainers_names[20][3]="NERD";
    preset_trainers_names[20][4]="NERD";
    preset_trainers_names[21][0]="PKMNIAC";
    preset_trainers_names[21][1]="u race yn?";
    preset_trainers_names[21][2]="u got glod?";
    preset_trainers_names[21][3]="PKMNIAC";
    preset_trainers_names[21][4]="PKMNIAC";
    preset_trainers_names[22][0]="BEAUTY";
    preset_trainers_names[22][1]="BEAUTY";
    preset_trainers_names[22][2]="BEAUTY";
    preset_trainers_names[22][3]="BEAUTY";
    preset_trainers_names[22][4]="BEAUTY";
    preset_trainers_names[23][0]="COOL♂";
    preset_trainers_names[23][1]="COOL♂";
    preset_trainers_names[23][2]="COOL♂";
    preset_trainers_names[23][3]="COOL♂";
    preset_trainers_names[23][4]="COOL♂";
    preset_trainers_names[24][0]="COOL♀";
    preset_trainers_names[24][1]="COOL♀";
    preset_trainers_names[24][2]="COOL♀";
    preset_trainers_names[24][3]="COOL♀";
    preset_trainers_names[24][4]="COOL♀";
    preset_trainers_names[25][0]="HIKER";
    preset_trainers_names[25][1]="HIKER";
    preset_trainers_names[25][2]="HIKER";
    preset_trainers_names[25][3]="HIKER";
    preset_trainers_names[25][4]="HIKER";
    preset_trainers_names[26][0]="MEDIUM";
    preset_trainers_names[26][1]="MEDIUM";
    preset_trainers_names[26][2]="MEDIUM";
    preset_trainers_names[26][3]="MEDIUM";
    preset_trainers_names[26][4]="MEDIUM";
    preset_trainers_names[27][0]="SAILOR";
    preset_trainers_names[27][1]="Tabarly";
    preset_trainers_names[27][2]="SAILOR";
    preset_trainers_names[27][3]="SAILOR";
    preset_trainers_names[27][4]="SAILOR";
    preset_trainers_names[28][0]="OLD MAN";
    preset_trainers_names[28][1]="OLD MAN";
    preset_trainers_names[28][2]="OLD MAN";
    preset_trainers_names[28][3]="OLD MAN";
    preset_trainers_names[28][4]="OLD MAN";
    preset_trainers_names[29][0]="FISHER";
    preset_trainers_names[29][1]="Shark";
    preset_trainers_names[29][2]="FISHER";
    preset_trainers_names[29][3]="FISHER";
    preset_trainers_names[29][4]="FISHER";
    preset_trainers_names[30][0]="LAB MAN";
    preset_trainers_names[30][1]="CHIEF";
    preset_trainers_names[30][2]="LAB MAN";
    preset_trainers_names[30][3]="LAB MAN";
    preset_trainers_names[30][4]="LAB MAN";
    preset_trainers_names[31][0]="BURGLAR";
    preset_trainers_names[31][1]="BURGLAR";
    preset_trainers_names[31][2]="BURGLAR";
    preset_trainers_names[31][3]="BURGLAR";
    preset_trainers_names[31][4]="BURGLAR";
    preset_trainers_names[32][0]="BIRDBOY";
    preset_trainers_names[32][1]="BIRDBOY";
    preset_trainers_names[32][2]="BIRDBOY";
    preset_trainers_names[32][3]="BIRDBOY";
    preset_trainers_names[32][4]="BIRDBOY";
    preset_trainers_names[33][0]="JUDOBOY";
    preset_trainers_names[33][1]="Ryu";
    preset_trainers_names[33][2]="JUDOBOY";
    preset_trainers_names[33][3]="JUDOBOY";
    preset_trainers_names[33][4]="JUDOBOY";
    preset_trainers_names[34][0]="GAMBLER";
    preset_trainers_names[34][1]="72o";
    preset_trainers_names[34][2]="MR.OHKO";
    preset_trainers_names[34][3]="Run Killer";
    preset_trainers_names[34][4]="GAMBLER";
    preset_trainers_names[35][0]="JUGGLER";
    preset_trainers_names[35][1]="JUGGLER";
    preset_trainers_names[35][2]="JUGGLER";
    preset_trainers_names[35][3]="JUGGLER";
    preset_trainers_names[35][4]="JUGGLER";
    preset_trainers_names[36][0]="ROCKER";
    preset_trainers_names[36][1]="ROCKER";
    preset_trainers_names[36][2]="ROCKER";
    preset_trainers_names[36][3]="ROCKER";
    preset_trainers_names[36][4]="ROCKER";
    preset_trainers_names[37][0]="MR.FIX";
    preset_trainers_names[37][1]="Debugger";
    preset_trainers_names[37][2]="C++ dev";
    preset_trainers_names[37][3]="I like Qt";
    preset_trainers_names[37][4]="MR.FIX";
    preset_trainers_names[38][0]="BIKER";
    preset_trainers_names[38][1]="Cyclist";
    preset_trainers_names[38][2]="BIKER";
    preset_trainers_names[38][3]="BIKER";
    preset_trainers_names[38][4]="BIKER";
    preset_trainers_names[39][0]="CUEBALL";
    preset_trainers_names[39][1]="CUEBALL";
    preset_trainers_names[39][2]="CUEBALL";
    preset_trainers_names[39][3]="CUEBALL";
    preset_trainers_names[39][4]="CUEBALL";
    preset_trainers_names[40][0]="SWIMMER";
    preset_trainers_names[40][1]="SWIMMER";
    preset_trainers_names[40][2]="SWIMMER";
    preset_trainers_names[40][3]="SWIMMER";
    preset_trainers_names[40][4]="SWIMMER";
    preset_trainers_names[41][0]="TAMER";
    preset_trainers_names[41][1]="TAMER";
    preset_trainers_names[41][2]="TAMER";
    preset_trainers_names[41][3]="TAMER";
    preset_trainers_names[41][4]="TAMER";
    preset_trainers_names[42][0]="PSYCHIC";
    preset_trainers_names[42][1]="Uri Geller";
    preset_trainers_names[42][2]="PSYCHIC";
    preset_trainers_names[42][3]="PSYCHIC";
    preset_trainers_names[42][4]="PSYCHIC";
    preset_trainers_names[43][0]="ROCKET";
    preset_trainers_names[43][1]="ROCKET";
    preset_trainers_names[43][2]="ROCKET";
    preset_trainers_names[43][3]="ROCKET";
    preset_trainers_names[43][4]="ROCKET";
    preset_trainers_names[44][0]="98 CUP 1";
    preset_trainers_names[44][1]="98 CUP 1";
    preset_trainers_names[44][2]="98 CUP 1";
    preset_trainers_names[44][3]="98 CUP 1";
    preset_trainers_names[44][4]="98 CUP 1";
    preset_trainers_names[45][0]="98 CUP 2";
    preset_trainers_names[45][1]="98 CUP 2";
    preset_trainers_names[45][2]="98 CUP 2";
    preset_trainers_names[45][3]="98 CUP 2";
    preset_trainers_names[45][4]="98 CUP 2";
    preset_trainers_names[46][0]="98 CUP 3";
    preset_trainers_names[46][1]="98 CUP 3";
    preset_trainers_names[46][2]="98 CUP 3";
    preset_trainers_names[46][3]="98 CUP 3";
    preset_trainers_names[46][4]="98 CUP 3";
    preset_trainers_names[47][0]="98 CUP 4";
    preset_trainers_names[47][1]="98 CUP 4";
    preset_trainers_names[47][2]="98 CUP 4";
    preset_trainers_names[47][3]="98 CUP 4";
    preset_trainers_names[47][4]="98 CUP 4";
    preset_trainers_names[48][0]="98 CUP 5";
    preset_trainers_names[48][1]="98 CUP 5";
    preset_trainers_names[48][2]="98 CUP 5";
    preset_trainers_names[48][3]="98 CUP 5";
    preset_trainers_names[48][4]="98 CUP 5";
    preset_trainers_names[49][0]="98 CUP 6";
    preset_trainers_names[49][1]="98 CUP 6";
    preset_trainers_names[49][2]="98 CUP 6";
    preset_trainers_names[49][3]="98 CUP 6";
    preset_trainers_names[49][4]="98 CUP 6";
    preset_trainers_names[50][0]="98 CUP 7";
    preset_trainers_names[50][1]="98 CUP 7";
    preset_trainers_names[50][2]="98 CUP 7";
    preset_trainers_names[50][3]="98 CUP 7";
    preset_trainers_names[50][4]="98 CUP 7";
    preset_trainers_names[51][0]="METAPOD";
    preset_trainers_names[51][1]="SirMetapod";
    preset_trainers_names[51][2]="Escape Pod";
    preset_trainers_names[51][3]="Metagame";
    preset_trainers_names[51][4]="METAPOD";
    preset_trainers_names[52][0]="MEWTWO";
    preset_trainers_names[52][1]="OpieOP";
    preset_trainers_names[52][2]="MEWTWO";
    preset_trainers_names[52][3]="MEWTWO";
    preset_trainers_names[52][4]="MEWTWO";
    preset_trainers_names[53][0]="P1 P2";
    preset_trainers_names[53][1]="P3 P4";
    preset_trainers_names[53][2]="P1 P2";
    preset_trainers_names[53][3]="P1 P2";
    preset_trainers_names[53][4]="P1 P2";
}