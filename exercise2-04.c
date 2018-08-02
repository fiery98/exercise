#include <stdio.h>
#include <string.h>

void input(char line[]);

void squeeze(char s1[],char s2[]);

int main() {
    char line1[1000]={" "},line2[1000]={" "};
    input(line1);
    input(line2);
    printf("%s",line1);
    printf("%s",line2);
    squeeze(line1,line2);
    printf("%s",line1);
    return 0;
}

void input(char line[]){
    int i,c;
    for(i=0;i<100-1&&(c=getchar())!=EOF&&c!='\n';i++){
        line[i]=c;

    }
    if(c=='\n'){
        line[i]=c;
        i++;
    }
}

void squeeze(char s1[],char s2[]){
    int a,b,i,j,k;
    a=strlen(s1)+2;
    b=strlen(s2)+2;
    for(i=0;i<b;i++)
        for(j=0;j<a;j++){
            if(s1[j]==s2[i]){
                for(k=j;k<a;k++){
                    s1[k]=s1[k+1];
                }
                a--;
                j--;
            }
        }
}