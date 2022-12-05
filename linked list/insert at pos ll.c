#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node * next;
};


struct node* getnode(){
    struct node *p;
    p= (struct node*) malloc(sizeof(struct node));
    return p;
}

void insbeg(struct node **start,int x){
    struct node *p;
    p=getnode();
    p->info=x;
    p->next= *start;
    *start=p;
    
}

void traverse(struct node *start){
    struct node*p;
    p=start;
    while(p!=NULL){
        printf("%d ", p->info);
        p=p->next;
    }
}

void insend(struct node **start,int x){
    struct node*q, *p;
    q=*start;
    while(q->next!=NULL){
        q=q->next;

    }
    p=getnode();
    p->info=x;
    p->next=NULL;
    q->next=p;

}
void insaft(struct node **q, int x){
    struct node *p,*r;
    p=getnode();
    p->info=x;
    r=(*q)->next;  //p->next=q->next;
    p->next=r;     //q->next=p;
    (*q)->next=p;
}

int count(struct node **start){
    int c=0;
    struct node *q;
    q=*start;
    while(q!=NULL){
        c++;
        q=q->next;
    }
    return c;
}

int delbeg(struct node **start){
    if(*start==NULL){
        printf("void deletion");
        exit(1);
    }
    
    int x;
    struct node*p;
    p=*start;
    x=p->info;
    *start=(*start)->next;
    free(p);
    return x;
}

int delend(struct node **start){
    int x;
    struct node*p,*q;
    p=*start;
    q=NULL;
while(p->next!=NULL){
    q=p;
    p=p->next;
}
    q->next=NULL;
    x=p->info;
    //*start=(*start)->next;
    free(p);
    return x;
}

int delafter(struct node **p){
    if(*p==NULL || (*p)->next==NULL){
        printf("void deleteion");
        exit(1);
    }

    int x;
    struct node*q,*r;
    q=(*p)->next;
    r=q->next;
    (*p)->next=r;
    
    x=q->info;
    
    free(q);
    return x;
}

void insertatpos(struct node**start, int x, int n){
    int cnt= count(start);
    struct node*p;
    p=(*start);
    if(n==1){
        insbeg(start,x);
    }
    else if(n==count +1){
        insend(start,x);
    }
    else if(n>1 && n<=count){
        for(int i=1; i<n-1; i++){
            p=p->next;
        }
        insaft(&p,x);
    }
    else{
        printf("invalid insertion");
    }
}

int main(){
    struct node *start;
    struct node *p;
    start= NULL;
    insbeg(&start,10);
    insbeg(&start,20);
    insbeg(&start,30);
    insend(&start,40);
    traverse(start);
    printf("\n");
    insertatpos(&start, 100, 2);
    traverse(start);

}

