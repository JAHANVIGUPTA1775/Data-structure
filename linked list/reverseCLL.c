#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#include"circularLL.h"

void reverse(struct node**start){
    struct node*p,*r,*n,*c;
    p=*start;
    c=(*start)->next;
    n=(*start)->next->next;
    r=(*start)->next;

    do{
        c->next=p;
        p=c;
        c=n;
        if(n!=(*start)){
            n=n->next;
        }
        // else{
        //     c->next=p;
        //     p=c;
        // }
    }while(p!=(*start));

    (*start)=r;
    traverse(*start);
}

int main(){
    struct node*start;
    start=NULL;
    
    insbeg(&start,10);
    insbeg(&start,20);
    insbeg(&start,30);
    insbeg(&start,40);
    insbeg(&start,50);
    //traverse(start);
    //printf("\n");
    reverse(&start);
    

}