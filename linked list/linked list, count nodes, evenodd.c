#include<stdio.h>
#include<stdlib.h>
struct node{
    int info;
    struct node * next;
};

struct node *start;

struct node* getnode(){
    struct node *p;
    p= (struct node*) malloc(sizeof(struct node));
    return p;
}

insbeg(int x){
    struct node *p;
    p=getnode();
    p->info=x;
    p->next= start;
    start=p;
    
}

void traverse(){
    struct node*p;
    p=start;
    while(p!=NULL){
        printf("%d ", p->info);
        p=p->next;
    }
}

void insend(int x){
    struct node*q, *p;
    q=start;
    while(q->next!=NULL){
        q=q->next;

    }
    p=getnode();
    p->info=x;
    p->next=NULL;
    q->next=p;

}

int countnode(){
    int c=0;
    struct node *q;
    q=start;
    while(q!=NULL){
        c++;
        q=q->next;
    }
    return c;
}
void evenodd(){
    int e=0,o=0;
    struct node *q;
    q=start;
    while(q!=NULL){
        if(q->info%2==0){
            e++;
        }
        else{
            o++;
        }
        
        q=q->next;
    }
    printf("e:%d o:%d", e,o);
    
}




int main(){
    start= NULL;   //initially it contain no node
    insbeg(100);
    insbeg(201);
    insbeg(300);
    insbeg(401);
    insbeg(500);
    insend(10);
    insend(20);
    insend(30);
    traverse();
    printf("%d", countnode());
    printf("\n");
    evenodd();
}