#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 1
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

void concatenate(struct node **start1, struct node **start2)
{
    struct node *p;
    p= *start1;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next= *start2;
    //return start1;
}

int middle(struct node**start){
    struct node*t,*r;
    t= *start;
    r=(*start);
    while(r!=NULL && r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
    }
    return t->info;
}
int cycledetection(struct node**start){
    struct node*t,*r;
    t= *start;
    r=(*start);
    
    while(r!=NULL && r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r){
            
            return 1;
        }
    }
    
    return 0;
}

int cyclelength(struct node**start){
    struct node*t,*r;
    t= *start;
    r=(*start)->next;
    while(r!=NULL && r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r){
            break;
        }
    }
    int c=0;
    do{
        c++;
        t=t->next;
    }while(t!=r);
    return c;
}

int cyclestartpoint(struct node**start){
    struct node*t,*r,*p;
    int c=0;
    t=*start;
    r=*start;
    p=*start;
    while(r!=NULL && r->next!=NULL){
        t=t->next;
        r=r->next;
        r=r->next;
        if(t==r){
            p=p->next;
            r=r->next;
            if(r==p){
                return r->info;
            }
        }
    }
    return 0;
}



int main(){
    struct node *start;
    start = NULL;
    struct node*p,*q;
    insbeg(&start,1);
    insbeg(&start,2);
    insbeg(&start,3);
    insbeg(&start,4);
    insbeg(&start,5);
    insbeg(&start,6);
    insbeg(&start,7);
    insbeg(&start,8);
    insbeg(&start,9);
    insbeg(&start,10);
    traverse(start);
    printf("\n");

    printf("middle is %d",middle(&start));
    


    p=start;
    while(p->next!=NULL){
        p=p->next;
    }
    printf("\n%d",p->info);
    q=start;
    while(q->info!=4){
        q=q->next;
    }
    printf("\n%d",q->info);
    p->next=q;

    printf("\nis cycle?: %d",cycledetection(&start));
    printf("\ncycle length: %d",cyclelength(&start));

    printf("\nstarting point%d",cyclestartpoint(&start));
}