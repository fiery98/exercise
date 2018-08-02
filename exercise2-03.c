#include <stdio.h>

int input(int line[]);

int main() {
    int a,i,length,number,rightorfault;
    int line[100];
    number=0;
    if((length=input(line))>0){
        length=length-1;
        if(length<2)
            rightorfault=0;
        else{
            for(i=0;i<length-1;i++){
                if(line[i]=='0'&&(line[i+1]=='x'||line[i+1]=='X')) {
                    rightorfault=1;
                    for (i = i + 2; i < length ; i++) {
                        if (line[i] == 48)
                            number = number * 16 + 0;
                        else if (line[i] == 49)
                            number = number * 16 + 1;
                        else if (line[i] == 50)
                            number = number * 16 + 2;
                        else if (line[i] == 51)
                            number = number * 16 + 3;
                        else if (line[i] == 52)
                            number = number * 16 + 4;
                        else if (line[i] == 53)
                            number = number * 16 + 5;
                        else if (line[i] == 54)
                            number = number * 16 + 6;
                        else if (line[i] == 55)
                            number = number * 16 + 7;
                        else if (line[i] == 56)
                            number = number * 16 + 8;
                        else if (line[i] == 57)
                            number = number * 16 + 9;
                        else if (line[i] == 65 || line[i] == 97)
                            number = number * 16 + 10;
                        else if (line[i] == 66 || line[i] == 98)
                            number = number * 16 + 11;
                        else if (line[i] == 67 || line[i] == 99)
                            number = number * 16 + 12;
                        else if (line[i] == 68 || line[i] == 100)
                            number = number * 16 + 13;
                        else if (line[i] == 69 || line[i] == 101)
                            number = number * 16 + 14;
                        else if (line[i] == 70 || line[i] == 102)
                            number = number * 16 + 15;
                        else {
                            rightorfault=0;
                            break;
                        }
                    }
                    break;
                }
                else
                    rightorfault=0;
            }
        }
        if(rightorfault==0)
            printf("wrong input");
        else if(rightorfault==1)
            printf("%d",number);
    }
    return 0;
}

int input(int line[]){
    int i,c;
    for(i=0;i<100-1&&(c=getchar())!=EOF&&c!='\n';i++){
        line[i]=c;

    }
    if(c=='\n'){
        line[i]=c;
        i++;
    }
    return i;
}