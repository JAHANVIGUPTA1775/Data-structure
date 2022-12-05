
#include <stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node*next;
};

struct node*getnode(){
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    return p;
}

void insbeg(struct node**cstart,int x){
    struct node*p;
    p=getnode();
    p->info=x;
    
    if((*cstart)!=NULL){
        p->next=(*cstart)->next;
        (*cstart)->next=p;
    }
    else{
        *cstart=p;
        (*cstart)->next=p;
    }
    
}

void insend(struct node**cstart,int x){
    struct node*p;
    p=getnode();
    p->info=x;
    if((*cstart)!=NULL){
        p->next=(*cstart)->next;
        (*cstart)->next=p;
        *cstart=p;
    }
    else{
        *cstart=p;
        (*cstart)->next=p;
    }
}

void insafter(struct node**q,int x){
    struct node*p;
    
    if(q==NULL){
        printf("void insertion");
    }
    else{
        p=getnode();
        p->info=x;
        p->next=(*q)->next;
        (*q)->next=p;
    }
    
}

int delbeg(struct node**cstart){
    struct node*p;
    p=(*cstart)->next;
    (*cstart)->next=p->next;
    
    if((*cstart)->next==(*cstart)){
        *cstart=NULL;
    }
    int x=p->info;
    free(p);
    return x;
}

int delend(struct node**cstart){
    struct node*p,*q;
    q=*cstart;
    p=(*cstart)->next;
    while(p!=(*cstart)){
        p=p->next;
    }
    p->next=(*cstart)->next;
    
    (*cstart)=p;
    
    int x=q->info;
    free(q);
    return x;
}

int delafter(struct node**q){
    struct node*p;
    p=(*q)->next;
    (*q)->next=p->next;
    int x=p->info;
    free(p);
    return x;
}

void traverse(struct node*cstart){
    struct node*p;
    p=cstart->next;
    
    while(p!=cstart){
        printf("%d ",p->info);
            p=p->next;
        
    }
    printf("%d ",p->info);
}

int main()
{
    struct node*cstart;
    cstart=NULL;
    insbeg(&cstart,10);
    insbeg(&cstart,20);
    insbeg(&cstart,30);
    insbeg(&cstart,40);
    insend(&cstart,50);
    traverse(cstart);
    printf("\n");

    // struct node*p;
    // p=cstart;
    // for(int i=0; i<2; i++){
    //     p=p->next;
    // }
    // delafter(&p);
    // printf("\n");
    // traverse(cstart);
    
    
    
    return 0;
}
