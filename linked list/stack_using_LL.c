#include <stdio.h>
#include<stdlib.h>
#include"myLL.h"
#define TRUE 1
#define FALSE 0
#define stacksize 10

struct stack{
    int top;
    int item[stacksize];
};



void initialize(struct node**top){
    top=NULL;
}

void push(struct node**top,int x){
    insbeg(top,x);
}

int pop(struct node**top){
    int x=delbeg(top);
    return x;
}

// stacktop(struct node**top){
//     struct node*p;
    
// }

int main()
{
    struct node*top;
    top=NULL;
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    push(&top, 40);
    traverse(top);
    printf("\n");

    int x=pop(&top);
    printf("deleted element is %d", x);
    printf("\n");
    return 0;
}
