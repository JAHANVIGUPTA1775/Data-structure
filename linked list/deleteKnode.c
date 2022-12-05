#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#include"myLL.h"

void deleteKnode(struct node**start, int k){
    struct node*p,*q;
    p=(*start);
    int i=1,x;
    while(i<=k){
        i=i+1;
        if(p!=NULL){
            p=p->next;
        }
        else{
            printf("void deletion");
        }
    }
    q=(*start);
    if(p!=NULL){
        while(p->next!=NULL){
            q=q->next;
            p=p->next;
        }
        x=delafter(&q);
    }
    else{
        x=delbeg(&(*start));
    }
    //traverse(start);
}

int main(){
    struct node*start;
    start=NULL;
    int k=10;
    insbeg(&start,10);
    insbeg(&start,9);
    insbeg(&start,8);
    insbeg(&start,7);
    insbeg(&start,6);
    insbeg(&start,5);
    insbeg(&start,4);
    insbeg(&start,3);
    insbeg(&start,2);
    insbeg(&start,1);
    
    traverse(start);
    printf("\n");
    deleteKnode(&start,k);
    traverse(start);


    
}