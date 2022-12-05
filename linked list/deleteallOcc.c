#include <stdio.h>
#include<stdlib.h>
#include"myLL.h"

struct node *  deleteallOccurance(struct node**start,int x)
{
    struct node*p,*q;
    p=*start;
    q=NULL;

    while(p!=NULL){
        if(p->info==x){
            if(q==NULL){
                p=p->next;
                delbeg(&start);
            }
            else{
                p=p->next;
                delafter(&q);
            }
        }
        else{
            q=p;
            p=p->next;
        }
    }
    p=*start;
    return p;

}


int main()
{
    struct node*start,*a;
    start=NULL;
    int x=3;
    insbeg(&start,10);
    insbeg(&start,3);

    insbeg(&start,20);
    insbeg(&start,3);
    insbeg(&start,30);
    insbeg(&start,40);
    traverse(start);
    printf("\n");
    a=deleteallOccurance(&start,x);
    traverse(a);
    return 0;
}
