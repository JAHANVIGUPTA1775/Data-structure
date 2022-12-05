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

int Inistialize(){
    S.TOP=-1;
}

int IsEmpty(){
    if(S.TOP==-1)
        return TRUE;
    else
        return FALSE;
}

char Push(char x){
    if(S.TOP==STACKSIZE-1){
        printf("stack overflows");
        exit(1);
    }
    S.TOP= S.TOP+1;
    S.item[S.TOP]=x;
    
}

char Pop(){
    char x;
    if(IsEmpty()){
        printf("stack underdflows");
        exit(1);
    }
     x= S.item[S.TOP];
    S.TOP= S.TOP-1;
    return x;
    
}
char StackTop(){
    char x= S.item[S.TOP];
    return x;
}

int evaluate(int a, int b, char op){
    switch(op){
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
        case '^': return pow(a,b);
    }
}



int main()
{
    char ps[20], symb;
    int a,b,i=0, val,x;
    gets(ps);
    strrev(ps);
    while(ps[i]!='\0'){
        symb= ps[i];
        if(symb>='0' && symb<='9'){
            Push(symb-48);
        }
        else{
            a=Pop();
            b=Pop();
            val= evaluate(a,b,symb);
            Push(val);
        }
        i++;
        
    }
    x=Pop();
    printf("%d", x);
    return 0;
}

