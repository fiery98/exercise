#include <stdio.h>

int main() {
    printf("Celsius      Fahrenheit\n");
    int c;
    float f;
    c=0;
    while(c<=300){
        f=9.0*c/5.0 +32;
        printf("  %3d           %6.2f\n",c,f);
        c=c+20;
    }
    return 0;
}