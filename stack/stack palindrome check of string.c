#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 20
#define TRUE 1
#define FALSE 0
struct stack{
    char item[STACKSIZE];
    int TOP;
};
/*************************/
struct stack s;
/*****************/
initialise(){
    s.TOP=-1;
}
/********************************/
int isempty(){
    if (s.TOP==-1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
/********************************/
push(char x){
    if(s.TOP==STACKSIZE-1){
        printf("stack overflow");
        exit(1);
    }
    s.TOP=s.TOP+1;
    s.item[s.TOP]=x;
}
/********************************/
char pop(){
    if (isempty(s)){
        printf("stack underflow");
        exit(1);
    }
    char x=s.item[s.TOP];
    s.TOP=s.TOP-1;
    return x;
}
/********************************/
char stacktop(){
    char x=s.item[s.TOP];
    return x;
}


/********************************/

int main(){
    struct stack s;
    int i=0, j=0;
    char x, str[10];
    char answer[10];
    initialise();
    scanf("%s", str);
    while(str[i]!='\0'){
        push(str[i]);
        i++;
    }
    while(!isempty()){
        x=pop();
        answer[j]=x;
        j++;
        
    }
    answer[j]='\0';
    int c=strcmp(str, answer);
    //printf("%s", answer);
    if(c==0){
        printf("palindrome");
    }
    else{
        printf("not palindrome");
    }
    
}
