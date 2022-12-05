#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSIZE 20
#define TRUE 1
#define FALSE 0
struct stack{
    int item[STACKSIZE];
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
push(int x){
    if(s.TOP==STACKSIZE-1){
        printf("stack overflow");
        exit(1);
    }
    s.TOP=s.TOP+1;
    s.item[s.TOP]=x;
}
/********************************/
int pop(){
    if (isempty(s)){
        printf("stack underflow");
        exit(1);
    }
    int x=s.item[s.TOP];
    s.TOP=s.TOP-1;
    return x;
}
/********************************/
int stacktop(){
    int x=s.item[s.TOP];
    return x;
}


/********************************/

int main(){
    char s[20];
    gets(s);
    initialise();
    int i=0;
    while(s[i]!='\0'){
        if(s[i]=='('){
            push("(");
        }
        else if(s[i]==')'){
            pop();
        }
        i++;
    }
    if(isempty()){
        printf("true");
    }
    else{
        printf("false");
    }
    return 0;
}
