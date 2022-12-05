#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 1
struct node{
    int info;
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
        printf("%d ", p->info);
        p=p->next;
    }
}

void insbeg(struct node**start,int x){
    struct node*p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
}

void insend(struct node**start,int x){
    struct node*p,*q;
    q=*start;
    p=getnode();
    while(q->next!=NULL){
        q=q->next;
    }
    p->info=x;
    p->next=NULL;
    q->next=p;
}

int count(struct node**start){
    struct node*p;
    p=*start;
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

void concatenate(struct node **start1, struct node **start2)
{
    struct node *p;
    p= *start1;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next= *start2;
    //return start1;
}

struct node *middle(struct node**start){
    struct node*t,*r;
    t= *start;
    r=(*start)->next;
    while(r!=NULL && r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
    }
    return t;
}

int cycledetection(struct node**start){
    struct node*t,*r;
    t= *start;
    r=(*start)->next;
    while(r!=NULL && r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r){
            return TRUE;
        }
    }
    return FALSE;
}

struct node* cyclelength(struct node**start){
    struct node*t,*r;
    t= *start;
    r=(*start)->next;
    while(r!=NULL && r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r){
            break;
        }
    }
    int c=0;
    do{
        c++;
        t=t->next;
    }while(t!=r);
    return c;
}



int main(){
    struct node *start1;
    struct node *start2;
    
    //struct node*p;
    start1 = NULL;
    start2 = NULL;


    insbeg(&start1,40);
    insbeg(&start1,30);
    insbeg(&start1,20);
    insbeg(&start1,10);
    insbeg(&start2,70);
    insbeg(&start2,60);
    insbeg(&start2,50);

    concatenate(&start1, &start2);
    traverse(start1);

    
    
    
}