#include <stdio.h>
#include <stdlib.h>
#include"myLL.h"

struct node* middle(struct node**start){
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

struct node* binarySearch(struct node**start,int x){
    struct node*mid;
    while((*start)->next!=NULL){
        mid=middle(start);
        if(mid->info==x){
        return mid;
    }
    else{
        if(x<mid->info){
            mid->next=NULL;
        }
        else{
            (*start)=mid->next;
        }
        }
    }
    if((*start)->info==x){
        return start;
    }
    else{
        return NULL;
    }
    

}

int main()
{
    struct node*start,*p;
    start=NULL;
    int x;
    insbeg(&start,10);
    insend(&start,20);
    insend(&start,30);
    insend(&start,40);
    insend(&start,50);
    insend(&start,60);
    //printf("%d",middle(&start));
    p=binarySearch(&start,70);
    if(p!=NULL){
        printf("element present");
    }
    else{
        printf("element not present");
    }
}