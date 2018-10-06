#include <stdio.h>

void setbits(unsigned int x,int p,int n);

int main() {
    unsigned int x;
    int p,n;
    scanf("%u%*c%d%*c%d%*c",&x,&p,&n);
    if(x>=0&&x<=4294967295){
        setbits(x,p,n);
    }
    else
        printf("wrong input");
    return 0;
}

void setbits(unsigned int x,int p,int n){
    printf("%u\n",x&(~0<<p)+((x>>(p-n))&~(~0<<n))+((x&~(~0<<(p-n)))<<n));
}