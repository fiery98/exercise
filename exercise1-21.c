#include <stdio.h>

int input(char output[]);

void entab(char c[],int a);

int main() {
    int lengths;
    char line[2000];
    while((lengths=input(line))>0){
        entab(line, lengths);
        printf("%s",line);
    }
    return 0;
}

int input(char line[]){
    int a,i;
    for(i=0;(a=getchar())!=EOF&&a!='\n'&&i<1999;i++)
        line[i]=a;
    if(a=='\n'){
        line[i]=a;
        i++;
    }
    return i;
}

void entab(char c[],int a){
    int i,j;
    for(i=0;i<1999-3;i++){
        if(c[i]==' '&&c[i+1]==' '&&c[i+2]==' '&&c[i+3]==' '){
            c[i]='\t';
            for(j=i+1;j<2000-3;j++)
                c[j]=c[j+3];
        }
    }
}