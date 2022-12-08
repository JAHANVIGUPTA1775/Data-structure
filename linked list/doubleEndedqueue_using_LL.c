#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#include"linked list/doublyLL.h"

void initialise(){
    struct node*front=NULL;
    struct node*rear=NULL;
}
isEmpty(struct node**front,struct node**rear){
    if(rear==NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
void insertfront(struct node**front,struct node**rear,int x){
    struct node*p;
    p=getnode();
    p->info=x;
    p->prev=NULL;
    p->next=*front;

    if((*front)!=NULL){
        (*front)->prev=p;
    }
    else{
        (*rear)=p;
    }
    (*front)=p;

}

void insertrear(struct node**front,struct node**rear,int x){
    struct node*p;
    p=getnode();
    p->info=x;
    p->next=NULL;
    p->prev=*rear;

    if((*rear)!=NULL){
        (*rear)->prev=p;
    }
    else{
        (*front)=p;
    }
    (*rear)=p;

}

int deletefront(struct node**front,struct node**rear){
    struct node*p;
    p=(*front);
    (*front)=(*front)->next;
    int x=p->info;
    free(p);
    if ((*front)==NULL){
        (*rear)=NULL;
    }
    else{
        (*front)->prev=NULL;
    }
    return x;
}

int deleterear(struct node**front,struct node**rear){
    struct node*p;
    p=(*rear);
    (*rear)=(*rear)->next;
    int x=p->info;
    free(p);
    if ((*rear)==NULL){
        (*front)=NULL;
    }
    else{
        (*rear)->prev=NULL;
    }
    return x;
}


int main()
{
    struct node*front,*rear;
    initialise();
    insertfront(&front,&rear,40);
    insertfront(&front,&rear,30);
    insertfront(&front,&rear,20);
    insertfront(&front,&rear,10);
    int x=deletefront(&front,&rear);
    printf("%d\n",x);
    x=deleterear(&front,&rear);
    printf("%d\n",x);
}