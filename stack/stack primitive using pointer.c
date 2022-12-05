#include <string.h>
#define STACKSIZE 10
#define TRUE 1
#define FALSE 0
struct stack{
    char item[STACKSIZE];
    int TOP;
};
/*********/

/*******/
initialise(struct stack *s){
    s->TOP=-1;
}
/************/
int isempty(struct stack *s){
    if (s->TOP==-1){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
/************/
push(struct stack *s,char x){
    if(s->TOP==STACKSIZE-1){
        printf("stack overflow");
        exit(1);
    }
    s->TOP=s->TOP+1;
    s->item[s->TOP]=x;
}
/************/
char pop(struct stack *s){
    if (isempty(s)){
        printf("stack underflow");
        exit(1);
    }
    char x=s->item[s->TOP];
    s->TOP=s->TOP-1;
    return x;
}
/************/
char stacktop(struct stack *s){
    char x=s->item[s->TOP];
    return x;
}

int main(){
    struct stack fs;
    initialise(&fs);
    char x;
    push(&fs,'p');
    push(&fs,'r');
    push(&fs,'a');
    push(&fs,'s');
    printf("%c",stacktop(&fs));
    x=pop(&fs);
    printf("%c\n",x);
     x=pop(&fs);
    printf("%c\n",x);
     x=pop(&fs);
    printf("%c\n",x);
}