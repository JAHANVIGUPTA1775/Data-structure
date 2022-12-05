#include <stdio.h>
#include<stdlib.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0

struct stack{
    char item[STACKSIZE];
    int TOP;
};

struct stack S;

void Inistialize(){
    S.TOP=-1;
}

int isempty(){
    if(S.TOP==-1)
        return TRUE;
    else
        return FALSE;
}

int push(int x){
    if(S.TOP==STACKSIZE-1){
        printf("stack overflows");
        exit(1);
    }
    S.TOP= S.TOP+1;
    S.item[S.TOP]=x;
    
}

int pop(){
    char x;
    if(isempty()){
        printf("stack underdflows");
        exit(1);
    }
     x= S.item[S.TOP];
    S.TOP= S.TOP-1;
    return x;
    
}
char StackTop(){
    int x= S.item[S.TOP];
    return x;
}

