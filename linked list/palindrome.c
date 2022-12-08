#include <stdio.h>
#include <stdlib.h>
#include"myLL.h"

struct node* reverse1(struct node**start){
    struct node*start2,*p;
    start2=NULL;
    p=*start;
    while(p!=NULL){
        insbeg(&start2,p->info);
        p=p->next;
    }
    //traverse(start2);
    return start2;
}

int isPalindrome(struct node**start){
    struct node*p,*q;
    p=*start;
    q=reverse1(start);
    while(p->next!=NULL){
        if(p->info!=q->info){
            return 0;
        }
        p=p->next;
        q=q->next;
    }
    return 1;
}






int main()
{
    struct node*start,*p;
    start=NULL;
    
    
    insend(&start,1);
    insend(&start,2);
    insend(&start,3);
    insend(&start,2);
    insend(&start,1);
    traverse(start);
    printf("\n");
    int x=isPalindrome(&start);
    if(x==1){
        printf("yes");
    }
    else{
        printf("no");
    }
    
    
}