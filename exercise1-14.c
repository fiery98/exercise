#include <stdio.h>

int main() {
    int i,j,input;
    int characters[26],output[100][26];
    j=0;
    for(i=0;i<26;++i){
        characters[i]=0;
    }
    while((input=getchar())!=EOF){
        if(input==65||input==97) characters[0]++;
        else if(input==66||input==98) characters[1]++;
        else if(input==67||input==99) characters[2]++;
        else if(input==68||input==100) characters[3]++;
        else if(input==69||input==101) characters[4]++;
        else if(input==70||input==102) characters[5]++;
        else if(input==71||input==103) characters[6]++;
        else if(input==72||input==104) characters[7]++;
        else if(input==73||input==105) characters[8]++;
        else if(input==74||input==106) characters[9]++;
        else if(input==75||input==107) characters[10]++;
        else if(input==76||input==108) characters[11]++;
        else if(input==77||input==109) characters[12]++;
        else if(input==78||input==110) characters[13]++;
        else if(input==79||input==111) characters[14]++;
        else if(input==80||input==112) characters[15]++;
        else if(input==81||input==113) characters[16]++;
        else if(input==82||input==114) characters[17]++;
        else if(input==83||input==115) characters[18]++;
        else if(input==84||input==116) characters[19]++;
        else if(input==85||input==117) characters[20]++;
        else if(input==86||input==118) characters[21]++;
        else if(input==87||input==119) characters[22]++;
        else if(input==88||input==120) characters[23]++;
        else if(input==89||input==121) characters[24]++;
        else if(input==90||input==122) characters[25]++;
    }
    for(i=0;i<26;i++){
        for(j=99;j>=0;j--){
            if(characters[i]>0){
                output[j][i]='|';
                characters[i]--;
            }
            else output[j][i]=' ';
        }
    }
    for(i=0;i<100;i++){
        for(j=0;j<26;j++){
            putchar(output[i][j]);
        }
        printf("\n");
    }
    return 0;
}