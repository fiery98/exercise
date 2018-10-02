#include <stdio.h>

void any(int s1[],int s2[]);

 int main(){
     int line1[1000],line2[1000];
     int c,i=0,j=0;
     while((c=getchar())!=EOF&&c!='\n'&&i<1000){
         line1[i]=c;
         i++;
     }
     while((c=getchar())!=EOF&&c!='\n'&&j<1000){
         line2[j]=c;
         j++;
     }
     any(line1,line2);
     return 0;
 }

 void any(int s1[],int s2[]){
     int c,i=0,j=0,n;
     while((c=s1[i])!='\n'&&i<1000&&c!=EOF&&c!='\0'){
         n=0;
         for(j=0;j<1000&&s2[j]!='\n'&&s2[j]!=EOF&&s2[j]!='\0';j++)
             if(s2[j]==c)
                 n++;
         if(n==0)
             printf("%c:-1\n",c);
         else
             printf("%c:%d\n",c,n);
         i++;
     }
 }