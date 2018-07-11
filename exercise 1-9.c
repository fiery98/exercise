#include <stdio.h>

int main() {
    int input,a=0;
    while((input=getchar())!=EOF) {
        if (input != ' ') {
            putchar(input);
            a=0;
        }
        else if (a == 0) {
            putchar(input);
            a=1;
        } else continue;
    }
    return 0;
}