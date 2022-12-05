#include <stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define STACKSIZE 10
#define TRUE 1
#define FALSE 0

struct stack{
    int item[STACKSIZE];
    int TOP;
};

struct stack S;

Initialize(){
    S.TOP=-1;
}

int IsEmpty(){
    if(S.TOP==-1)
        return TRUE;
    else
        return FALSE;
}

Push(int x){
    if(S.TOP==STACKSIZE-1){
        printf("stack overflows");
        exit(1);
    }
    S.TOP= S.TOP+1;
    S.item[S.TOP]=x;
    
}

Pop(){
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


/*****************************/
int evaluate(int a, int b, char op){
    switch(op){
        case '+': return a+b;
        case '*': return a*b;
        case '-': return a-b;
        case '&': return a&b;
        case '^': return pow(a,b);
        default: return a/b;
    }
}

/*****************************/

int main()
{
    int x, i=0, val, b,a;
    char ps[20];
    char symb;
    Initialize();
    scanf("%s", &ps);
    strrev(ps);
    while(ps[i]!='\0'){
        symb=ps[i];
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
