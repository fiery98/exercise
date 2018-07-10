#include <stdio.h>
int main() {
    printf("Fahrenheit  Celsius\n");
    int f=0;
    float c=0;
    while(f<=300){
        c=5.0*(f-32)/9.0;
        printf("  %3d        %6.2f\n",f,c);
        f=f+20;
    }
    return 0;
}