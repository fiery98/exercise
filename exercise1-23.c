#include <stdio.h>

int input(char output[]);

int main() {
    int i;
    char line[2000]={0};
    while((input(line))>0){
        printf("%s",line);
        for(i=0;i<2000&&line[i]!=0;i++)
            line[i]=0;
    }
    return 0;
}


int input(char line[]){                                                                                                  /* input the character and return how many characters have in this line */
    int a,b,i,StartComments,EndComments;
    StartComments=0;
    EndComments=0;
    for(i=0;(a=getchar())!=EOF&&a!='\n'&&i<1999;i++) {
        if(a=='/') {
            line[i]=a;
            StartComments=1;
        }
        else if(a=='*'&&StartComments==1) {
            while ((b=getchar())!=EOF) {
                if (b=='*')
                    EndComments = 1;
                else if (b=='/'&&EndComments==1)
                    break;
                else
                    EndComments=0;
            }
            StartComments=0;
            EndComments=0;
            i=i-2;
        }
        else {
            line[i]=a;
            StartComments=0;
        }
    }
    if(a=='\n'){
        line[i]=a;
        i++;
    }
    return i;
}