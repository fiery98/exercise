#include <stdio.h>

int input(char output[]);

void detab(char c[],int a);

void delete(char e[],int f);

void newline(char d[],int b);

int main() {
    int lengths;
    char line[2100];
    while((lengths=input(line))>0){
        detab(line, lengths);
        delete(line,lengths);
        if(lengths>20)
            newline(line,lengths);
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
            a=a+3;
        }
    }
}

void delete(char e[],int f){
    int i,j;
    for(i=0;i<f-2;i++){
        if(e[i]==' '&&e[i+1]==' '){
            for(j=0;j<f-1;j++){
                e[i+1+j]=e[i+2+j];
            }
            i--;
            f=f-1;
        }
    }
}

void newline(char d[],int b){
    int i,j,k;
    printf("%d\n",b);
    i=j=19;
    while(i<=b-2){
        if(d[j-1]!=' '&&d[j]!=' '){
            for(k=b;k>=j;k--)
                d[k+1]=d[k];
            d[j]='\n';
            j++;
        }
        if(d[j-1]==' '){
            d[j-1]='\n';
        }
        if(d[j]==' '){
            d[j]='\n';
            j++;
        }
        j=j+19;
        i=i+19;
    }
}