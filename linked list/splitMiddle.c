#include <stdio.h>
#include <stdlib.h>
#include"myLL.h"

int middle(struct node**start){
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

splitMiddle(struct node**start){
    struct node*p,*start2,*m;
    p=*start;
    start2=NULL;
    m=middle(start);
    start2=m->next;
    m->next=NULL;
    traverse(*start);
    printf("\n");
    traverse(start2);
}


int main()
{
    struct node*start;
    start=NULL;
    
    int x=30;
    
    insbeg(&start,10);
    insend(&start,20);
    insend(&start,30);
    insend(&start,40);
    insend(&start,50);
    insend(&start,60);
    //printf("%d",middle(&start));
    splitMiddle(&start);
}