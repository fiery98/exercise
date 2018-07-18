#include <stdio.h>

int input(char output[]);

int main() {
    char line[200];
    while((input(line))>0){
        printf("%s",line);
    }
    return 0;
}

int input(char line[]){
    int a,b,i,change1,change2,quit;
    change1=0;
    change2=0;
    quit=0;
    for(i=0;(a=getchar())!=EOF&&a!='\n'&&i<1999;i++){
        if(a=='/'&&change1!=1){
            change1=1;
        }
        else if(a=='/'&&change1==1){
            line[i-1]='/';
        }
        else if(a=='*'&&change1==1){
            while((b=getchar())!=EOF&&quit!=1){
                if(b=='*'){
                    change2=1;
                }
                else if(b=='/'&&change2==1){
                    quit=1;
                    change2=0;
                }
            }
            i--;
            if(b!='\n')
                line[i]=b;
            change1=0;
            quit=0;
        }
        else{
            line[i]=a;
            change1=0;
        }
    }
    if(a=='\n'){
        line[i]=a;
        i++;
    }
    return i;
}