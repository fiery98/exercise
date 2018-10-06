#include <stdio.h>

void rightrot(unsigned int x,int n);

int main() {
    unsigned int x;
    int n;
    scanf("%u%*c%d%*c",&x,&n);
    if(x>=0&&x<=4294967295){
        rightrot(x,n);
    }
    else
        printf("wrong input");
    return 0;
}

void rightrot(unsigned int x,int n){
    printf("%u\n",(x>>n)+(x<<(32-n)));
}