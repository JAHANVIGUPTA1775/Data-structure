#include <stdio.h>
#include <stdlib.h>
#include"myLL.h"

void pairSwap(struct node**start){
    struct node*p,*q;
    p=*start;
    q=(*start)->next;
    while(q!=NULL){
        int t=p->info;
        p->info=q->info;
        q->info=t;
        p=p->next->next;
        q=q->next;
        if(q!=NULL){
            q=q->next;
        }
    }
    traverse(*start);
}

int main()
{
    struct node*start;
    start=NULL;
    
    
    
    insbeg(&start,10);
    insend(&start,20);
    insend(&start,30);
    insend(&start,40);
    insend(&start,50);
    insend(&start,60);
    //printf("%d",middle(&start));
    pairSwap(&start);
}