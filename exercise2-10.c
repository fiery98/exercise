#include <stdio.h>

int lower(int x);

int main() {
    int c,i;
    for(i=0;(c=getchar())!='\n'&&i<1000;i++){
        printf("%c",lower(c));
    }
    return 0;
}

int lower(int x){
    return (x>='A'&&x<='Z')?(x+32):x;
}