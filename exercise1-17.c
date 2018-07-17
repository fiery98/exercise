#include <stdio.h>

int input(char output[]);

int main() {
    int lengths;
    char line[1000];
    while((lengths=input(line[]))>0){
        if(lengths>80){
            printf("%s",line);
        }
    }
    return 0;
}

int input(char line[]){
    int a,i;
    for(i=0;(a=getchar())!=EOF&&a!='\n'&&i<999;i++)
        line[i]=a;
    if(a=='\n'){
        line[i]=a;
        i++
    }
    return i;
}
