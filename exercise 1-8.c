#include <stdio.h>

int main() {
    int input,a=0,b=0,c=0;
    while((input=getchar())!=EOF){
        putchar(input);
        if(input==' ') a++;
        else if(input=='\t') b++;
        else if(input=='\n') c++;
    }
    printf("There's %d blanks, %d tabs and %d newlines\n",a,b,c);
    return 0;
}