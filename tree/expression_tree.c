#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

struct node{
    char data;
    struct node*left;
    struct node*right;
    struct node*next;
};

struct node*makenode(char x){
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    p->left=NULL;
    p->right=NULL;
    p->data=x;
    p->next=NULL;
    return p;
}

void inordertraversal(struct node*t){
    if(t!=NULL){
        inordertraversal(t->left);
        printf("%d ",t->data);
    
        inordertraversal(t->right);
    }
}

int prcd(char a,char b){
    if(a=='^' || a=='*' || a=='/' || a=='%'){
        if(b=='^'){
            return FALSE;
        }
        else{
            return TRUE;
        }
    }
    else{
        if(b=='+' || b=='-'){
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
}

struct node*buildExpressionTree(char exp[]){
    int i=0;
    char symbol,op;
    struct node*x,*y,*p,*q;
    struct node*start=NULL;
    char operatorstack[20];
    int top=-1;

    while(exp[i]!='\0'){
        symbol=exp[i];
        i++;
        if(symbol>='a' && symbol<='z'){
            x=makenode(symbol);
           //push(operandstack,x);
           x->next=start;
           start=x;
        }
        else{
            while(top!=-1 &&prcd(operatorstack[top],symbol)){
                
                op=operatorstack[top--];
                y=makenode(op);
                
                p=start;
                start=start->next;

                q=start;
                start=start->next;

                y->right=p;
                y->left=q;
                //push(operandstack,y);
                y->next=start;
                start=y;

            }
            //x->next=start;
            operatorstack[++top]=symbol;
        }
    }
    while(top!=-1){
                op=operatorstack[top--];
                y=makenode(op);
                
                p=start;
                start=start->next;

                q=start;
                start=start->next;

                y->right=p;
                y->left=q;
                //push(operandstack,y);
                y->next=start;
                start=y;
    }
    return start;
}



int main(){
    
    char exp[20];
    gets(exp);
    struct node*start;
    start=buildExpressionTree(exp);
    inordertraversal(start);

}