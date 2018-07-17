#include <stdio.h>

float change(int f);

int main() {
    printf("Fahrenheit  Celsius\n");
    int f;
    float c;
    f=0;
    while(f<=300){
        printf("  %3d        %6.2f\n",f,change(f));
        f=f+20;
    }
    return 0;
}

float change(int f){
    float c;
    c=5.0*(f-32)/9.0;
    return c;
}