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
    q=(*p)->next;  //q=p->next
    r=q->next;     //p->next=q->next
    (*p)->next=r;
    
    x=q->info;
    
    free(q);
    return x;
}

void orderedIns(struct node** start, int x){
    struct node *p, *q;
    p=(*start);
    q=NULL;
    while(p!=NULL && x>=p->info){
        q=p;
        p=p->next;
    }
    if (q==NULL){
        insbeg(start,x);
    }
    else{
        insaft(&q,x);
    }
}



int main(){
    struct node *start;
    //struct node *p;
    start= NULL;
    // insbeg(&start,100);
    // insbeg(&start,201);
    // insbeg(&start,300);
    // insbeg(&start,401);
    // insbeg(&start,500);
    // insend(&start,10);
    // insend(&start,20);
    // insend(&start,30);
    // traverse(start);
    orderedIns(&start,10);
    orderedIns(&start,1);
    orderedIns(&start,20);
    orderedIns(&start,5);
    traverse(start);




    //printf("%d",count(&start));

    // int x=delbeg(&start);
    // printf("\n");
    // printf("deleted element is %d", x);
    // printf("\n");
    // traverse(start);
    // printf("\n");

    // p=start;
    // for(int i=1; i<2; i++){
    //     p=p->next;
    // }
    // x= delafter(&p);
    // traverse(start);
    // printf("\n");
    // printf("deleted element is %d", x);

    // x=delend(&start);
    // printf("\n");
    // printf("deleted element is %d", x);
    // printf("\n");
    // traverse(start);
    // printf("\n");


}

