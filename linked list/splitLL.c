#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#include"myLL.h"

void split(struct node**start,int x){
    struct node*p,*start2;
    start2=NULL;
    p=*start;
    while(p->next!=NULL){
        
        if(p->info==x){
            start2=p->next;
            p->next=NULL;
            break;
        }
        else{
            p=p->next;
        }
    }
    traverse(*start);
    printf("\n");
    traverse(start2);
}

int main(){
    struct node*start;
    start=NULL;
    
    int x=30;
    
    insbeg(&start,10);
    insbeg(&start,20);
    insbeg(&start,30);
    insbeg(&start,40);
    insbeg(&start,50);
    split(&start,x);
    //traverse(start);

}