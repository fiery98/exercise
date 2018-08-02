#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    int i;
    /* first method */
    printf("signed char: %d ！ %d\nunsigned char: 0 ！ %u\n",SCHAR_MIN,SCHAR_MAX,UCHAR_MAX);
    printf("signed short: %d ！ %d\nunsigned short: 0-%u\n",SHRT_MIN,SHRT_MAX,USHRT_MAX);
    printf("signed int: %d ！ %d\nunsigned int: 0 ！ %u\n",INT_MIN,INT_MAX,UINT_MAX);
    printf("signed long: %ld ！ %ld\nunsigned long: 0 ！ %lu\n",LONG_MIN,LONG_MAX,ULONG_MAX);

    /* second method */
    unsigned char ch=1;
    char charmin,charmax;
    unsigned char ucharmax;
    for(i=1;i<8;i++)
        ch=ch*2;
    charmin=-ch;
    charmax=ch-1;
    ucharmax=ch*2-1;
    printf("signed char: %d ！ %d\nunsigned char: 0 ！ %u\n",charmin,charmax,ucharmax);
    unsigned short sh=1;
    short shortmin,shortmax;
    unsigned short ushortmax;
    for(i=1;i<16;i++)
        sh=sh*2;
    shortmin=-sh;
    shortmax=sh-1;
    ushortmax=sh*2-1;
    printf("signed short: %d ！ %d\nunsigned short: 0-%u\n",shortmin,shortmax,ushortmax);
    unsigned int in=1;
    int intmin,intmax;
    unsigned int uintmax;
    for(i=1;i<32;i++)
        in=in*2;
    intmin=-in;
    intmax=in-1;
    uintmax=in*2-1;
    printf("signed int: %d ！ %d\nunsigned int: 0 ！ %u\n",intmin,intmax,uintmax);
    unsigned long lo=1;
    long longmin,longmax;
    unsigned long ulongmax;
    for(i=1;i<64;i++)
        lo=lo*2;
    longmin=-lo;
    longmax=lo-1;
    ulongmax=lo*2-1;
    printf("signed long: %ld ！ %ld\nunsigned long: 0 ！ %lu\n",longmin,longmax,ulongmax);
    return 0;
}