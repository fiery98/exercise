#include <stdio.h>
int main() {
    printf("Fahrenheit  Celsius\n");
    int f;
    for(f=300;f>=0;f=f-20){
        printf("  %3d       %6.2f\n",f,5.0*(f-32)/9.0);
    }
    return 0;
}