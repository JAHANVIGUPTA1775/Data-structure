#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node * next;
};

struct node *start;

struct node* getnode(){
    struct node *p;
    p= (struct node*) malloc(sizeof(struct node));
    return p;
}

insbeg(int x){
    struct node *p;
    p=getnode();
    p->info=x;
    p->next= start;
    start=p;
    
}

void traverse(){
    struct node*p;
    p=start;
    while(p!=NULL){
        printf("%d ", p->info);
        p=p->next;
    }
}

void insend(int x){
    struct node*q, *p;
    q=start;
    while(q->next!=NULL){
        q=q->next;

    }
    p=getnode();
    p->info=x;
    p->next=NULL;
    q->next=p;

}
int count(){
    int c=0;
    struct node *q;
    q=start;
    while(q!=NULL){
        c++;
        q=q->next;
    }
    return c;
}
void Linear_Search(int x){
    struct node*p;
    p=start;
    int n=count();
    int c=0;
    for(int i=0 ; i<n ; i++){
        if(p->info==x){
            printf("Element Found at %d position",c+1) ;
            break;
        }
        c++;
        p=p->next;
    }

}

int main(){
    start= NULL;   //initially it contain no node
    insbeg(100);
    insbeg(201);
    insbeg(300);
    insbeg(401);
    insbeg(500);
    insend(10);
    insend(20);
    insend(30);
    traverse();
    Linear_Search(10);
}