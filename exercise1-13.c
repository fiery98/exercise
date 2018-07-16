#include <stdio.h>

int main() {
    int i,j,k,input;
    int lengths[100],output[20][100];
    j=k=0;
    for(i=0;i<100;i++){
        lengths[i]=0;
    }
    while((input=getchar())!=EOF){
        if(input>=65&&input<=90) lengths[j]++;
        else if(input>=97&&input<=122) lengths[j]++;
        else j++;
    }
    for(i=0;i<100;i++){
        if(lengths[i]==0){
            while(lengths[i]==0&&k<100)
            {
                for(j=i;j<100-i;j++) lengths[j]=lengths[j+1];
                k++;
            }
        }
    }
    for(i=0;i<100;i++){
        for(j=19;j>=0;j--){
            if(lengths[i]>0){
                output[j][i]='|';
                lengths[i]--;
            }
            else output[j][i]=' ';
        }
    }
    for(i=0;i<20;i++){
        for(j=0;j<100;j++){
            putchar(output[i][j]);
        }
        printf("\n");
    }
    return 0;
}