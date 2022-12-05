#include<stdio.h>
#include<stdlib.h>

#include"mystack.h"

int main(){
   int i=0;
   //char x;
   char str[10];
    
    scanf("%s", str);
    
    while(str[i]!='\0'){
        push(str[i]);
        i++;
    }

    while(!isempty()){
       // x=pop();
        printf("%c", pop());
    }
    return 0;
}