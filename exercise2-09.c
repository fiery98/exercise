#include <stdio.h>

int bitcount(unsigned int x);

int main() {
    unsigned int x;
    scanf("%u%*c",&x);
    if(x>=0&&x<=4294967295){
        printf("%d",bitcount(x));
    }
    else
        printf("wrong input");
    return 0;
}

int bitcount(unsigned int x){
    int b=0;
    while(x!=0){
        x&=(x-1);
        b++;
    }
    return b;
}