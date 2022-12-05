#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct node{
    int info;
    struct node *next;
};

struct node* getnode(){
    struct node*p;
    p= (struct node*)malloc(sizeof(struct node));
    return p;
}

void traverse(struct node *start){
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
    if(q==NULL){
        insbeg(start,x);
    }

    else{
        while(q->next!=NULL){
        q=q->next;
    }
    p=getnode();
    p->info=x;
    p->next=NULL;
    q->next=p;
    }
    
}
void insaft(struct node **q, int x){
    struct node *p,*r;
    p=getnode();
    p->info=x;
    r=(*q)->next;  //p->next=q->next;
    p->next=r;     //q->next=p;
    (*q)->next=p;
}

int delbeg(struct node **start){
    if(*start==NULL){
        printf("void deletion");
        exit(1);
    }
    
    int x;
    struct node*p;
    p=*start;
    x=p->info;
    *start=(*start)->next;
    free(p);
    return x;
}

int delend(struct node **start){
    int x;
    struct node*p,*q;
    p=*start;
    q=NULL;
while(p->next!=NULL){
    q=p;
    p=p->next;
}
    q->next=NULL;
    x=p->info;
    //*start=(*start)->next;
    free(p);
    return x;
}

int delafter(struct node **p){
    if(*p==NULL || (*p)->next==NULL){
        printf("void deleteion");
        exit(1);
    }

    int x;
    struct node*q,*r;
    q=(*p)->next;
    r=q->next;
    (*p)->next=r;
    
    x=q->info;
    
    free(q);
    return x;
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

void orderedIns(struct node** start, int x){
    struct node *p, *q;
    p=(*start);
    q=NULL;
    while(p!=NULL && x>=p->info){
        q=p;
        p=p->next;
    }
    if (q==NULL){
        insbeg(start,x);
    }
    else{
        insaft(&q,x);
    }
}