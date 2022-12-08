#include <stdio.h>
#include <stdlib.h>
#include"myLL.h"

struct node*mergePoint(struct node**start1,struct node**start2 ){
    struct node*p,*q;
    p=*start1;
    q=*start2;
    int m=count(start1);
    int n=count(start2);
    if(m>n){
        for(int i=0; i<(m-n);i++){
            p=p->next;
        }
    }
    else if(n>m){
        for(int i=0; i<(n-m);i++){
            q=q->next;
        }
    }
    while(p!=q){
        p=p->next;
        q=q->next;
    }
    return p;
}

int main()
{
    struct node*start1,*start2,*p,*q,*k;
    start1=NULL;
    
    
    insbeg(&start1,1);
    insend(&start1,2);
    insend(&start1,3);
    insend(&start1,4);
    insend(&start1,5);
    insend(&start1,6);
    insend(&start1,7);
    insend(&start1,8);
    start2=NULL;
    insend(&start2,10);
    insend(&start2,11);

    p=start1;
    q=start2;
    while(p->next!=NULL){
        if(p->info==5){
            break;
        }
        p=p->next;
    }

     while(q->next!=NULL){
        q=q->next;
    }
    q->next=p;

    traverse(start1);
    printf("\n");
    traverse(start2);
     printf("\n");
    k=mergePoint(&start1,&start2);
    printf("%d", k->info);

    
    
}