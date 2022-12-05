#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#include"myLL.h"

void copy(struct node**start){
    struct node*p,*start2;
    p=*start;
    start2=NULL;
    while(p=NULL){
        insend(&start2,p->info);
        p=p->next;
    }
    traverse(start2);
}

int main(){
    struct node*start;
    start=NULL;
    
    
    
    insbeg(&start,10);
    insbeg(&start,20);
    insbeg(&start,30);
    insbeg(&start,40);
    insbeg(&start,50);
    traverse(start);
    printf("\n");
    copy(&start);
    //traverse(start);

}