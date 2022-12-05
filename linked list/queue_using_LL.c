#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define queuesize 10
//#include"myLL.h"
struct node{
    int info;
    struct node *next;
};
void traverse(struct node *start){
    struct node*p;
    p=start;
    while(p!=NULL){
        printf("%d ", p->info);
        p=p->next;
    }
}
struct node* getnode(){
    struct node*p;
    p= (struct node*)malloc(sizeof(struct node));
    return p;
}
void insbeg(struct node**start,int x){
    struct node*p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
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
struct queue{
    int rear;
    int front;
    int item[queuesize];
};

void enque(struct node**front,struct node**rear, int x){
    if(*rear==NULL){
        insbeg(rear,x);
        *front=*rear;
    }

    else{
        insaft(rear,x);
        *rear=(*rear)->next;
    }
}
int deque(struct node**front,struct node**rear){
    int x;
    if(*front==NULL){
        printf("deletion not possible");
        exit(1);
    }
    else{
         x=delbeg(front);
        if(*front==NULL){
            *rear=NULL;
        }
    }
    return x;
}

int main(){
    struct node*front,*rear;
    front=NULL;
    rear=NULL;
    
    enque(&front,&rear,100);
    enque(&front,&rear,200);
    enque(&front,&rear,300);
    traverse(front);
    printf("\n");

    int x=deque(&front,&rear);
    printf("deleted value is:%d",x);

}