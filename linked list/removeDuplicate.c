#include <stdio.h>
#include <stdlib.h>
#include"myLL.h"

void removeDuplicates(struct node**start){
    struct node*p,*q,*r;
    p=(*start);
    r=p;
    q=p->next;
    while(p!=NULL){
        while(q!=NULL){
            if(q->info==p->info){
                q=q->next;
                delafter(&r);
            }
            else{
                r=r->next;
                q=q->next;
            }
        }
        p=p->next;
        r=p;
        if(p!=NULL){
            q=p->next;
        }
    }
}

int main()
{
    struct node*start,*p;
    start=NULL;
    
    
    insbeg(&start,1);
    insend(&start,1);
    insend(&start,1);
    insend(&start,1);
    insend(&start,1);
    insend(&start,1);
    insend(&start,4);
    insend(&start,3);
    insend(&start,6);
    insend(&start,7);
    traverse(start);
    removeDuplicates(&start);
    printf("\n");
    traverse(start);
    
}