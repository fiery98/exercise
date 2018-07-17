#include <stdio.h>

int input(char output[]);

void reverse(char s[],int lengths);

int main() {
    int lengths;
    char line[1000];
    while((lengths=input(line))>0){
        lengths=lengths-2;
        reverse(line,lengths);
        printf("%s",line);
    }
    return 0;
}

int input(char line[]){
    int a,i;
    for(i=0;(a=getchar())!=EOF&&a!='\n'&&i<999;i++)
        line[i]=a;
    if(a=='\n'){
        line[i]=a;
        i++;
    }
    return i;
}

void reverse(char s[],int lengths){
    int i;
    char a;
    for(i=0;i<lengths/2;i++){
        a=s[i];
        s[i]=s[lengths-i];
        s[lengths-i]=a;
    }
}