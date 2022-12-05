#include<stdio.h>
#include<stdlib.h>
#define stacksize 10
#define true 1
#define false 0

struct stack{
    int item[stacksize];
    int top;
};

//struct stack s;

void initialize(struct stack *s){
   s->top=-1;
}

int isempty(struct stack *s){
    if(s->top==-1){
        return true;
    }
    else{
        return false;
    }
}

int pop(struct stack *s){
    if(isempty(s)){
        printf("stack underflow");
        exit(1);
    }
    int x= s->item[s->top];
    s->top= s->top-1;
    return x;
}

void push(struct stack *s,int x){
    if(s->top==stacksize-1){
        printf("stackoverflow");
        exit(1);
    }
    s->top= s->top+1;
    s->item[s->top]= x;
}

int stacktop(struct stack *s){
    int x= s->item[s->top];
    return x;
}

int main()
{
    int x;
    struct stack fs;
    initialize(&fs);
    push(&fs,100);
    push(&fs,200);
    push(&fs,300);
    //printf("%d", s.top);
    x= pop(&fs);
    printf("\n%d", x);
    x= pop(&fs);
    printf("\n%d", x);
    printf("%d", stacktop(&fs));
    
    
    return 0;
}
