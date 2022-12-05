#include<stdio.h>
#include<stdlib.h>
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

// void reverse1(struct node**start){
//     struct node*start2,*p;
//     start2=NULL;
//     p=*start;
//     while(p!=NULL){
//         insbeg(&start2,p->info);
//         p=p->next;
//     }
//     traverse(start2);
// }

void reverse2(struct node**start){
    struct node*c,*p,*n;
    c=*start;
    p=NULL;
    n=c->next;
    
    while(c!=NULL){
        c->next=p;
        p=c;
        c=n;
        if(n!=NULL){
            n=n->next;
        }
    }
    (*start)=p;
    
    //traverse(start);
}



int main(){
    struct node*start;
    start=NULL;
    insbeg(&start,10);
    insbeg(&start,20);
    insbeg(&start,30);
    reverse2(&start);
    traverse(start);
    
}
