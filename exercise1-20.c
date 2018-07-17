#include <stdio.h>

int input(char output[]);

void detab(char c[],int a);

int main() {
    int lengths;
    char line[2000];
    while((lengths=input(line))>0){
        detab(line, lengths);
        printf("%s",line);
    }
    return 0;
}

int input(char line[]){
    int a,i;
    for(i=0;(a=getchar())!=EOF&&a!='\n'&&i<499;i++)
        line[i]=a;
    if(a=='\n'){
        line[i]=a;
        i++;
    }
    return i;
}

void detab(char c[],int a){
    int i,j;
    for(i=0;i<500;i++){
        if(c[i]=='\t'){
            for(j=a+3;j>i+3;j--){
                c[j]=c[j-3];
            }
            c[i]=' ';
            c[i+1]=' ';
            c[i+2]=' ';
            c[i+3]=' ';
            i=i+4;
        }
    }
}