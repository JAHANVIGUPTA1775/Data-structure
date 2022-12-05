#include <stdio.h>
#include<stdlib.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0

struct stack{
    int item[STACKSIZE];
    int TOP;
};

struct stack S;

int Inistialize(){
    S.TOP=-1;
}

int IsEmpty(){
    if(S.TOP==-1)
        return TRUE;
    else
        return FALSE;
}

int Push(int x){
    if(S.TOP==STACKSIZE-1){
        printf("stack overflows");
        exit(1);
    }
    S.TOP= S.TOP+1;
    S.item[S.TOP]=x;
    
}

int Pop(){
    int x;
    if(IsEmpty()){
        printf("stack underdflows");
        exit(1);
    }
     x= S.item[S.TOP];
    S.TOP= S.TOP-1;
    return x;
    
}
int StackTop(){
    int x= S.item[S.TOP];
    return x;
}

int main()
{
    int x;
    Inistialize();
    Push(100);
    Push(200);
    Push(300);
    Push(400);
    Push(500);
    Push(600);
    Push(700);
    Push(800);
    Push(900);
    Push(1000);
    //Push(1100);
    x= Pop();
    printf("%d", x);
    
    return 0;
}

