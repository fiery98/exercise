#include <stdio.h>

int main() {
    int i,c;
    int line[1000];
    for(i=0;i<1000-1;i++){
        c=getchar();
        if(c==EOF)
            break;
        else if(c=='\n')
            break;
        else
            line[i]=c;
    }
    if(c=='\n'){
        line[i]=c;
        i++;
    }
    printf("%s",line);
    return 0;
}