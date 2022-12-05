#include <stdio.h>
#include <stdlib.h>

#include"myLL.h"



void createLL(struct node**head){
    struct node*p;
    p=getnode();
    (*head)=p;
    (*head)->info=0;
    (*head)->next=0;

}

void insbegin(struct node**head, int x){
    insaft(&(*head),x);
    (*head)->info=(*head)->info+1;
}



int main()
{
    struct node *start;
    start = NULL;

    
    createLL(&start);
    insbegin(&start, 1);
    insbegin(&start, 2);
    insbegin(&start, 3);
    insbegin(&start, 4);
    

    traverse(start);
    
}