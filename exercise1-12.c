#include <stdio.h>

int main() {
    int input;
    while((input=getchar())!=EOF){
        if(input==' ') printf("\n");
        else putchar(input);
    }
    return 0;
}