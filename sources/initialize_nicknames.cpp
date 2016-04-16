#include "mainwindow.h"

void MainWindow::initialize_nicknames(){
    for(short i=0;i<256;i++) {
        for(short j=0;j<10;j++){
            preset_nicknames[i][j]=pkm_name[i];
        }
    }
    preset_nicknames[1][1]="bulbasaur";
    preset_nicknames[1][2]="SAURBULBA";
    preset_nicknames[1][3]="BULBASTOR";
    preset_nicknames[1][8]="Fushinoko";
    preset_nicknames[1][9]="Bulbapedia";
    preset_nicknames[2][1]="ivysaur";
    preset_nicknames[2][2]="SAURIVY";
    preset_nicknames[2][3]="IVYSTOR";
    preset_nicknames[2][8]="Poison Ivy";
    preset_nicknames[2][9]="Lierre";
    preset_nicknames[3][1]="venusaur";
    preset_nicknames[3][2]="SAURVENU";
    preset_nicknames[3][3]="VENUSTOR";
    preset_nicknames[3][8]="VENUSTOISE";
    preset_nicknames[3][9]="Belladonna";
    preset_nicknames[4][1]="charmander";
    preset_nicknames[4][7]="Takenori";
    preset_nicknames[5][1]="charmeleon";
    preset_nicknames[6][1]="charizard";
    preset_nicknames[6][2]="ZARDCHARI";
    preset_nicknames[6][4]="Lizardon";
    preset_nicknames[6][8]="CharHazard";
    preset_nicknames[6][9]="Shivan Drg";
    preset_nicknames[7][1]="squirtle";
    preset_nicknames[8][1]="wartortle";
    preset_nicknames[9][1]="blastoise";
    preset_nicknames[9][4]="Kamex";
    preset_nicknames[9][6]="ShellShock";
    preset_nicknames[9][7]="Panzer";
    preset_nicknames[9][8]="VENUSTOISE";
    preset_nicknames[9][9]="WaterKoopa";
    preset_nicknames[10][1]="caterpie";
    preset_nicknames[10][9]="SQUEESHY";
    preset_nicknames[11][1]="metapod";
    preset_nicknames[11][8]="SirMetapod";
    preset_nicknames[11][9]="METAGAME";
    preset_nicknames[12][1]="butterfree";
    preset_nicknames[12][2]="FREEBUTTER";
    preset_nicknames[12][8]="Margarine";
    preset_nicknames[12][9]="G. Freeman";
    preset_nicknames[13][1]="weedle";
    preset_nicknames[13][9]="CUDDLEME";
    preset_nicknames[14][1]="kakuna";
    preset_nicknames[15][1]="beedrill";
    preset_nicknames[15][2]="DRILLBEE";
    preset_nicknames[15][7]="CHIKUCHIKU";
    preset_nicknames[15][8]="STINGER";
    preset_nicknames[15][9]="Kamina";
    preset_nicknames[16][1]="pidgey";
    preset_nicknames[16][8]="aaabaaajss";
    preset_nicknames[16][9]="Bird Jesus";
    preset_nicknames[17][1]="pidgeotto";
    preset_nicknames[17][8]="aaabaaajss";
    preset_nicknames[17][9]="Bird Jesus";
    preset_nicknames[18][1]="pidgeot";
    preset_nicknames[18][6]="MARTY";
    preset_nicknames[18][7]="Matsumiya";
    preset_nicknames[18][8]="aaabaaajss";
    preset_nicknames[18][9]="Bird Jesus";
    preset_nicknames[19][1]="rattata";
    preset_nicknames[20][1]="raticate";
    preset_nicknames[21][1]="spearow";
    preset_nicknames[21][9]="the Dragon";
    preset_nicknames[22][1]="fearow";
    preset_nicknames[23][1]="ekans";
    preset_nicknames[23][2]="SNAKE";
    preset_nicknames[23][9]="ItsASnake!";
    preset_nicknames[24][1]="arbok";
    preset_nicknames[24][2]="KOBRA";
    preset_nicknames[25][1]="pikachu";
    preset_nicknames[25][2]="CHUKAPI";
    preset_nicknames[26][1]="raichu";
    preset_nicknames[27][1]="sandshrew";
    preset_nicknames[27][9]="Badger";
    preset_nicknames[28][1]="sandslash";
    preset_nicknames[28][2]="SLASHSAND";
    preset_nicknames[29][1]="nidoran♀";
    preset_nicknames[30][1]="nidorina";
    preset_nicknames[30][2]="RINANIDO";
    preset_nicknames[31][1]="nidoqueen";
    preset_nicknames[31][2]="QUEENNIDO";
    preset_nicknames[32][1]="nidoran♂";
    preset_nicknames[33][1]="nidorino";
    preset_nicknames[33][2]="RINONIDO";
    preset_nicknames[34][1]="nidoking";
    preset_nicknames[34][2]="KINGNIDO";
    preset_nicknames[34][9]="X ACCURACY";
    preset_nicknames[35][1]="clefairy";
    preset_nicknames[35][2]="FAIRYCLE";
    preset_nicknames[36][1]="clefable";
    preset_nicknames[36][2]="FABLECLE";
    preset_nicknames[37][1]="vulpix";
    preset_nicknames[37][9]="Firefox";
    preset_nicknames[38][1]="ninetales";
    preset_nicknames[38][2]="TALESNINE";
    preset_nicknames[38][8]="9 tails";
    preset_nicknames[38][9]="Firefox";
    preset_nicknames[39][1]="jigglypuff";
    preset_nicknames[39][8]="Lullaby";
    preset_nicknames[39][9]="DoTheLala";
    preset_nicknames[40][1]="wigglytuff";
    preset_nicknames[41][1]="zubat";
    preset_nicknames[42][1]="golbat";
    preset_nicknames[42][9]="FirstBlood";
    preset_nicknames[43][1]="oddish";
    preset_nicknames[44][1]="gloom";
    preset_nicknames[44][8]="MOOGLE";
    preset_nicknames[44][9]="Gloomy";
    preset_nicknames[45][1]="vileplume";
    preset_nicknames[45][9]="Rafflesia";
    preset_nicknames[46][1]="paras";
    preset_nicknames[46][9]="Mushroom";
    preset_nicknames[47][1]="parasect";
    preset_nicknames[47][9]="Mushroom";
    preset_nicknames[48][1]="venonat";
    preset_nicknames[49][1]="venomoth";
    preset_nicknames[50][1]="diglett";
    preset_nicknames[50][9]="Boota";
    preset_nicknames[51][1]="dugtrio";
    preset_nicknames[51][9]="DUGGY";
    preset_nicknames[52][1]="meowth";
    preset_nicknames[53][1]="persian";
    preset_nicknames[54][1]="psyduck";
    preset_nicknames[54][2]="DUCKPSY";
    preset_nicknames[55][7]="Masuda";
    preset_nicknames[55][9]="ToiletDuck";
    preset_nicknames[55][1]="golduck";
    preset_nicknames[55][2]="DUCKGOL";
    preset_nicknames[55][9]="ToiletDuck";
    preset_nicknames[56][1]="mankey";
    preset_nicknames[56][9]="Monkey!";
    preset_nicknames[57][1]="primeape";
    preset_nicknames[57][9]="Ape Escape";
    preset_nicknames[58][1]="growlithe";
    preset_nicknames[58][9]="FrankerZ";
    preset_nicknames[59][1]="arcanine";
    preset_nicknames[59][8]="RK9";
    preset_nicknames[59][9]="FrankerZ";
    preset_nicknames[60][1]="poliwag";
    preset_nicknames[60][7]="Tajiri";
    preset_nicknames[61][1]="poliwhirl";
    preset_nicknames[62][1]="poliwrath";
    preset_nicknames[63][1]="abra";
    preset_nicknames[64][1]="kadabra";
    preset_nicknames[64][2]="DABRAKA";
    preset_nicknames[64][4]="Yungerer";
    preset_nicknames[64][9]="Uri Geller";
    preset_nicknames[65][1]="alakazam";
    preset_nicknames[65][2]="KAZAMALA";
    preset_nicknames[65][4]="Foodin";
    preset_nicknames[65][9]="Uri Geller";
    preset_nicknames[66][1]="machop";
    preset_nicknames[66][2]="CHOPPMA";
    preset_nicknames[67][1]="machoke";
    preset_nicknames[67][2]="CHOKEPMA";
    preset_nicknames[68][1]="machamp";
    preset_nicknames[68][2]="CHAMPMA";
    preset_nicknames[69][1]="bellsprout";
    preset_nicknames[69][2]="SPROUTBELL";
    preset_nicknames[69][9]="JUDOPLANT";
    preset_nicknames[70][1]="weepinbell";
    preset_nicknames[70][9]="Ringabel";
    preset_nicknames[71][1]="victreebel";
    preset_nicknames[71][9]="Ringabel";
    preset_nicknames[72][1]="tentacool";
    preset_nicknames[72][2]="COOLTENTA";
    preset_nicknames[73][1]="tentacruel";
    preset_nicknames[73][2]="CRUELTENTA";
    preset_nicknames[73][9]="Yamete!";
    preset_nicknames[74][1]="geodude";
    preset_nicknames[74][9]="Hey dude";
    preset_nicknames[75][1]="graveler";
    preset_nicknames[76][1]="golem";
    preset_nicknames[76][2]="LEMGO";
    preset_nicknames[76][8]="Pebble";
    preset_nicknames[76][9]="Rhinestone";
    preset_nicknames[77][1]="ponyta";
    preset_nicknames[77][9]="My Little";
    preset_nicknames[78][1]="rapidash";
    preset_nicknames[79][1]="slowpoke";
    preset_nicknames[79][8]="649Pokémon";
    preset_nicknames[79][9]="G5confirmd";
    preset_nicknames[80][1]="slowbro";
    preset_nicknames[80][7]="NoCritPlz";
    preset_nicknames[80][8]="IHateCrits";
    preset_nicknames[80][9]="Tobybro";
    preset_nicknames[81][1]="magnemite";
    preset_nicknames[82][1]="magneton";
    preset_nicknames[82][2]="TONMAGNE";
    preset_nicknames[82][9]="MAGGIE";
    preset_nicknames[83][1]="farfetch'd";
    preset_nicknames[83][7]="CH'DING";
    preset_nicknames[83][8]="ToiletDuck";
    preset_nicknames[83][9]="DUX";
    preset_nicknames[84][1]="doduo";
    preset_nicknames[84][2]="DUODO";
    preset_nicknames[85][1]="dodrio";
    preset_nicknames[85][2]="DRIODO";
    preset_nicknames[85][9]="DORIS";
    preset_nicknames[86][1]="seel";
    preset_nicknames[87][1]="dewgong";
    preset_nicknames[87][2]="GONGDEW";
    preset_nicknames[88][1]="grimer";
    preset_nicknames[89][1]="muk";
    preset_nicknames[90][1]="shellder";
    preset_nicknames[91][1]="cloyster";
    preset_nicknames[91][3]="CLOYSTOR";
    preset_nicknames[92][1]="gastly";
    preset_nicknames[92][9]="Ghastly";
    preset_nicknames[93][1]="haunter";
    preset_nicknames[94][1]="gengar";
    preset_nicknames[94][7]="Sugimori";
    preset_nicknames[94][8]="ToothPaste";
    preset_nicknames[94][9]="Colgate";
    preset_nicknames[95][1]="onix";
    preset_nicknames[95][7]="SolidSnake";
    preset_nicknames[95][8]="Onixpected";
    preset_nicknames[95][9]="Rocky";
    preset_nicknames[96][1]="drowzee";
    preset_nicknames[96][9]="ZZZzzzZZZ";
    preset_nicknames[97][1]="hypno";
    preset_nicknames[97][7]="No Hype";
    preset_nicknames[97][8]="Hypster";
    preset_nicknames[97][9]="Kidnapper";
    preset_nicknames[98][1]="krabby";
    preset_nicknames[98][1]="BYKRAB";
    preset_nicknames[99][1]="kingler";
    preset_nicknames[99][9]="Wrong King";
    preset_nicknames[100][1]="voltorb";
    preset_nicknames[100][9]="Poké Ball";
    preset_nicknames[101][1]="electrode";
    preset_nicknames[101][9]="Poké Ball";
    preset_nicknames[102][1]="exeggcute";
    preset_nicknames[102][9]="NotSoCute";
    preset_nicknames[103][1]="exeggutor";
    preset_nicknames[103][3]="EXEGGUSTOR";
    preset_nicknames[103][7]="Ishihara";
    preset_nicknames[103][8]="Eggy";
    preset_nicknames[103][9]="Aubergine";
    preset_nicknames[104][1]="cubone";
    preset_nicknames[105][1]="marowak";
    preset_nicknames[105][2]="WAKMARO";
    preset_nicknames[105][9]="JoltWak";
    preset_nicknames[106][1]="hitmonlee";
    preset_nicknames[106][9]="Bruce Lee";
    preset_nicknames[107][1]="hitmonchan";
    preset_nicknames[107][9]="Haymaker";
    preset_nicknames[108][1]="lickitung";
    preset_nicknames[109][1]="koffing";
    preset_nicknames[109][8]="AzurHeight";
    preset_nicknames[109][9]="Smogon";
    preset_nicknames[110][1]="weezing";
    preset_nicknames[110][8]="Weeeeeeeee";
    preset_nicknames[110][9]="Smogogo";
    preset_nicknames[111][1]="rhyhorn";
    preset_nicknames[112][1]="rhydon";
    preset_nicknames[112][2]="DONRHY";
    preset_nicknames[112][3]="DONSTOR";
    preset_nicknames[113][1]="chansey";
    preset_nicknames[114][1]="tangela";
    preset_nicknames[114][2]="GELATAN";
    preset_nicknames[114][9]="CRINKLES";
    preset_nicknames[115][1]="kangaskhan";
    preset_nicknames[115][2]="KHANKANGAS";
    preset_nicknames[115][9]="GengisKhan";
    preset_nicknames[116][1]="horsea";
    preset_nicknames[116][4]="Seahorse";
    preset_nicknames[117][1]="seadra";
    preset_nicknames[117][2]="DRASEA";
    preset_nicknames[118][1]="goldeen";
    preset_nicknames[118][2]="DEENGOL";
    preset_nicknames[118][9]="GoldeenBoy";
    preset_nicknames[119][1]="seaking";
    preset_nicknames[119][2]="KINGSEA";
    preset_nicknames[119][5]="SeakingMsl";
    preset_nicknames[119][6]="HideN'Seak";
    preset_nicknames[119][7]="FUCK YEAH";
    preset_nicknames[119][8]="SeakNDstry";
    preset_nicknames[119][9]="ZeRealKing";
    preset_nicknames[120][1]="staryu";
    preset_nicknames[120][9]="StarFox";
    preset_nicknames[121][1]="starmie";
    preset_nicknames[121][2]="MIESTAR";
    preset_nicknames[121][3]="STARMISTOR";
    preset_nicknames[121][9]="StarFox";
    preset_nicknames[122][1]="mr.mime";
    preset_nicknames[122][9]="MARCEL";
    preset_nicknames[123][1]="scyther";
    preset_nicknames[123][9]="DontRunWth";
    preset_nicknames[124][1]="jynx";
    preset_nicknames[124][8]="ZYNX";
    preset_nicknames[124][9]="LOLA";
    preset_nicknames[125][1]="electabuzz";
    preset_nicknames[125][2]="BUZZELECTA";
    preset_nicknames[125][9]="BlitzKrieg";
    preset_nicknames[126][1]="magmar";
    preset_nicknames[127][1]="pinsir";
    preset_nicknames[127][9]="MightyBug";
    preset_nicknames[128][1]="tauros";
    preset_nicknames[128][2]="ROSTAU";
    preset_nicknames[128][3]="TAUROSTOR";
    preset_nicknames[128][9]="King of G1";
    preset_nicknames[129][1]="magikarp";
    preset_nicknames[129][2]="KARPMAGI";
    preset_nicknames[129][9]="Magikrap";
    preset_nicknames[130][1]="gyarados";
    preset_nicknames[130][9]="Serpentide";
    preset_nicknames[131][1]="lapras";
    preset_nicknames[131][3]="LAPRASTOR";
    preset_nicknames[132][1]="ditto";
    preset_nicknames[132][9]="Shapeshift";
    preset_nicknames[133][1]="eevee";
    preset_nicknames[134][1]="vaporeon";
    preset_nicknames[134][9]="Faporeon";
    preset_nicknames[135][1]="jolteon";
    preset_nicknames[135][3]="JOLTESTOR";
    preset_nicknames[135][8]="Usain Jolt";
    preset_nicknames[135][9]="King of CH";
    preset_nicknames[136][1]="flareon";
    preset_nicknames[137][1]="porygon";
    preset_nicknames[137][2]="GONPORY";
    preset_nicknames[137][5]="Debian0.93";
    preset_nicknames[137][6]="Rndmzr 0.1";
    preset_nicknames[137][7]="255 items";
    preset_nicknames[137][8]="8F ACE";
    preset_nicknames[109][9]="AzurHeight";
    preset_nicknames[138][1]="omanyte";
    preset_nicknames[138][2]="NITEOMA";
    preset_nicknames[138][7]="Anarchy";
    preset_nicknames[138][8]="Democracy";
    preset_nicknames[138][9]="Lord Helix";
    preset_nicknames[139][1]="omastar";
    preset_nicknames[139][2]="STAROMA";
    preset_nicknames[139][6]="ImAStar";
    preset_nicknames[139][7]="Anarchy";
    preset_nicknames[139][8]="Democracy";
    preset_nicknames[139][9]="Lord Helix";
    preset_nicknames[140][1]="kabuto";
    preset_nicknames[140][2]="TOKABU";
    preset_nicknames[140][7]="Anarchy";
    preset_nicknames[140][8]="Democracy";
    preset_nicknames[140][9]="DomeFossil";
    preset_nicknames[141][1]="kabutops";
    preset_nicknames[141][2]="TOPSKABU";
    preset_nicknames[141][6]="OverTheTop";
    preset_nicknames[141][7]="Anarchy";
    preset_nicknames[141][8]="Democracy";
    preset_nicknames[141][9]="DomeFossil";
    preset_nicknames[142][1]="aerodactyl";
    preset_nicknames[142][2]="DACTYLAERO";
    preset_nicknames[142][9]="Mantdactyl";
    preset_nicknames[143][1]="snorlax";
    preset_nicknames[143][2]="LAXSNOR";
    preset_nicknames[143][7]="Nishino";
    preset_nicknames[143][8]="King of G2";
    preset_nicknames[143][9]="FishLax";
    preset_nicknames[144][1]="articuno";
    preset_nicknames[144][2]="CUNOARTI";
    preset_nicknames[145][1]="zapdos";
    preset_nicknames[145][2]="DOSZAP";
    preset_nicknames[145][3]="ZAPSTOR";
    preset_nicknames[145][8]="Thor";
    preset_nicknames[145][9]="ThnderBird";
    preset_nicknames[146][1]="moltres";
    preset_nicknames[146][2]="TRESMOL";
    preset_nicknames[146][9]="Sulfura";
    preset_nicknames[147][1]="dratini";
    preset_nicknames[147][2]="TINIDRA";
    preset_nicknames[148][1]="dragonair";
    preset_nicknames[148][2]="NAIRDRAGO";
    preset_nicknames[149][1]="dragonite";
    preset_nicknames[149][2]="NITEDRAGO";
    preset_nicknames[150][1]="mewtwo";
    preset_nicknames[150][2]="TWOMEW";
    preset_nicknames[150][9]="OpieOP";
    preset_nicknames[151][1]="mew";
    preset_nicknames[151][3]="MEWSTOR";
    preset_nicknames[151][6]="BART";
    preset_nicknames[151][7]="Morimoto";
    preset_nicknames[151][8]="Matsumiya";
    preset_nicknames[151][9]="The Truck";
}
