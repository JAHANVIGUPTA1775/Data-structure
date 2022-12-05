#include <stdio.h>
#include<stdlib.h>

struct node{
    int coeff;
    int exponent;
    struct node *next;
};



struct node* getnode(){
    struct node*p;
    p= (struct node*)malloc(sizeof(struct node));
    return p;
}

void traverse(struct node*start){
    struct node*p;
    p=start;
    while(p!=NULL){

        if(p->next==NULL){
            printf("%dx^%d", p->coeff,p->exponent);
            p=p->next;
        }
        else{
            printf("%dx^%d+ ", p->coeff,p->exponent);
            p=p->next;
        }

        
    }
}

void insbeg(struct node**start,int x,int y){
    struct node*p;
    p=getnode();
    p->coeff=x;
    p->exponent=y;
    p->next=*start;
    *start=p;
}

void insend(struct node **start,int x,int y){
    struct node*p,*q;
    q=*start;
    p=getnode();
    if(q==NULL)
    {
        insbeg(start,x,y);
    }
    else
    {
    while(q->next!=NULL){
        q=q->next;
    }
    p->coeff=x;
    p->exponent=y;
    p->next=NULL;
    q->next=p;
    }
}

void insaft(struct node**q,int x,int y){
    struct node*p;
    p=getnode();
    p->coeff=x;
    p->exponent=y;
    p->next= (*q)->next;
    (*q)->next=p;
}

void orderedins(struct node**start, int x,int y){
    struct node *p, *q;
    p=*start;
    q=NULL;
    while(p!=NULL && y>=p->exponent){
        q=p;
        p=p->next;
    }
    if(q==NULL){
        insbeg(start,x,y);
    }
    else{
        insaft(&q,x,y);
    }

}

int delafter(struct node **p){
    

    int x;
    struct node*q,*r;
    q=(*p)->next;
    r=q->next;
    (*p)->next=r;
    
    x=q->coeff;
    free(q);
    return x;
}