#include <stdio.h>

int main() {
    int c;
    while((c=getchar())!=EOF){
        if((c!=EOF)==1) printf("1");
        else if((c!=EOF)==0) printf("0");
        else break;
    }
    return 0;
}