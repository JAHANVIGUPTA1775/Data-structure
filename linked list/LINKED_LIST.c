#include<stdio.h>
#include<stdlib.h>

struct node{
    int info;
    struct node *next;
};



struct node* getnode(){
    struct node*p;
    p= (struct node*)malloc(sizeof(struct node));
    return p;
}

void traverse(struct node*start){
    struct node*p;
    p=start;
    while(p!=NULL){
        printf("%d ", p->info);
        p=p->next;
    }
}

void insbeg(struct node**start,int x){
    struct node*p;
    p=getnode();
    p->info=x;
    p->next=*start;
    *start=p;
}

void insend(struct node**start,int x){
    struct node*p,*q;
    q=*start;
    p=getnode();
    while(q->next!=NULL){
        q=q->next;
    }
    p->info=x;
    p->next=NULL;
    q->next=p;
}

void insaft(struct node**q,int x){
    struct node*p;
    p=getnode();
    p->info=x;
    p->next= (*q)->next;
    (*q)->next=p;
}

int count(struct node**start){
    struct node*p;
    p=*start;
    int c=0;
    while(p!=NULL){
        c++;
        p=p->next;
    }
    return c;
}

int delbeg(struct node**start){
    struct node*p;
    p=*start;
    int x=p->info;
    *start=(*start)->next;
    free(p);
    return x;
}

int delafter(struct node**p){
    struct node*q;
    q=(*p)->next;
    (*p)->next=q->next;
    int x= q->info;
    free(q);
    //free(q);
    return x;
}

int delend(struct node**start){
    struct node *p, *q;
    p=*start;
    q=NULL;
    while(p->next!=NULL){
        q=p;
        p=p->next;
    }
    q->next=NULL;
    int x=p->info;
    free(p);
    return x;
}

void orderedins(struct node**start, int x){
    struct node *p, *q;
    p=*start;
    q=NULL;
    while(p!=NULL && x>=p->info){
        q=p;
        p=p->next;
    }
    if(q==NULL){
        insbeg(start,x);
    }
    else{
        insaft(&q,x);
    }

}

void pqins(struct node**start, int x){
    orderedins(start,x);
}
void pqdeletion(struct node**start){
    int x=delbeg(start);
    return x;
}

void insertatpos(struct node**start, int x, int n){
    struct node*p;
    int cnt=count(start);
    if(n==1){
        insbeg(start,x);
    }
    else if(n==cnt+1){
        insend(start,x);
    }
    else if(n>1 && n<=cnt){
        p=*start;
        for(int i=0; i<n-1; i++){
            p=p->next;
        }
        insaft(&p,x);
    }
    else{
        printf("invalid");
    }
}


int main(){
    struct node*start;
    struct node*p;
    start = NULL;
    insbeg(&start,11);
    insbeg(&start,5);
    insbeg(&start,20);
    insbeg(&start,10);
    traverse(start);
    printf("\n");
    insend(&start,15);
    traverse(start);
    // printf("\n");
    // printf("count is %d", count(&start));
    // printf("\n");


    // p=start;
    // for(int i=0; i<3; i++){
    //     p=p->next;
    // }
    // insaft(&p,100);
    // traverse(start);
    // printf("\n");


    // int x=delbeg(&start);
    // printf("element deleted is %d",x);
    // printf("\n");
    // traverse(start);
    // printf("\n");


    // p=start;
    // for(int i=0; i<1; i++){
    //     p=p->next;
    // }
    // x=delafter(&p);
    // printf("element deleted is %d",x);
    // printf("\n");
    // traverse(start);
    // printf("\n");


    // x=delend(&start);
    // printf("element deleted is %d",x);
    // printf("\n");
    // traverse(start);

    // orderedins(&start,10);
    // orderedins(&start,1);
    // orderedins(&start,20);
    // orderedins(&start,5);
    // traverse(start);

    // pqins(&start,10);
    // pqins(&start,1);
    // pqins(&start,8);
    // pqins(&start,15);
    // traverse(start);

    // insertatpos(&start, 100,3);
    // traverse(start);
}