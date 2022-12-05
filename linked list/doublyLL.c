#include <stdio.h>
#include<stdlib.h>
struct dnode{
    int info;
    struct dnode*next;
    struct dnode*prev;
};

struct dnode*getnode(){
    struct dnode*p;
    p=(struct dnode*)malloc(sizeof(struct dnode));
    return p;
}

void insbeg(struct dnode**dstart,int x){
    struct dnode*p;
    p=getnode();
    p->info=x;
    
    p->prev=NULL;
    p->next=*dstart;
    if(*dstart!=NULL){
        (*dstart)->prev=p;
    }
    *dstart=p;
    
}

void insend(struct dnode**dstart,int x){
    struct dnode*p,*q;
    p=*dstart;
    q=getnode();
    q->info=x;
    q->next=NULL;
    if((*dstart)!=NULL){
        while(p->next!=NULL){
            p=p->next;
        }
         p->next=q;
        q->prev=p;
    }
    else{
        q->prev=NULL;
        *dstart=q;
    }
   
}

void insafter(struct dnode**p,int x){
    struct dnode*q,*r;
    
    q=getnode();
    q->info=x;
    r=(*p)->next;
    (*p)->next=q;
    (q)->prev=(*p);
    (q)->next=r;
    if(r!=NULL){
        r->prev=q;
    }
    
}

void insbefore(struct dnode**p,int x){
    struct dnode*q,*r;
    
    q=getnode();
    q->info=x;
    r=(*p)->prev;
    if(r!=NULL){
        r->next=q;
    }
    
    q->prev=r;
    q->next=(*p);
    (*p)->prev=q;
}

int delbeg(struct dnode**dstart){
    struct dnode * p;
    if(*dstart!=NULL){
        p=*dstart;
        *dstart=p->next;
        int x=p->info;
        free(p);
        if(*dstart!=NULL){
            (*dstart)->prev=NULL;
        }
        return x;
    }
    else{
        printf("void deletion");
    }
}

int delend(struct dnode**dstart){
    struct dnode * p,*q;
    p=*dstart;
    while(p->next!=NULL){
        p=p->next;
    }
    q=p->prev;
    q->next=NULL;
    int x=p->info;
    free(p);
    return x;

}

int delafter(struct dnode**p){
    struct dnode*q,*r;
    q=(*p)->next;
    r=q->next;
    (*p)->next=r;
    r->prev=(*p);
    int x=q->info;
    free(q);
    return x;

}
int delspecific(struct dnode**p){
    struct dnode*q,*r;
    q=(*p)->prev;
    r=(*p)->next;
    q->next=r;
    r->prev=q;
    int x=(*p)->info;
    free(*p);
    return x;
}


void traverse(struct dnode*dstart){
    struct dnode * p;
    p=dstart;
    
    while(p!=NULL){
        printf("%d ",p->info);
            p=p->next;
        
    }
    
}




int main()
{
    struct dnode*dstart;
    dstart=NULL;
    insbeg(&dstart,10);
    insbeg(&dstart,20);
    insbeg(&dstart,30);
    insbeg(&dstart,40);
    insend(&dstart,50);
    insend(&dstart,30);
    insend(&dstart,20);
    traverse(dstart);
    printf("\n");

    struct dnode*p;
    p=dstart;
    for(int i=0; i<3; i++){
        p=p->next;
    }
    insafter(&p,100);
    traverse(dstart);
    printf("\n");
    

    p=dstart;
    for(int i=0; i<1; i++){
        p=p->next;
    }
    insbefore(&p,200);
    traverse(dstart);
    printf("\n");


    int x=delbeg(&dstart);
    printf("element deleted is %d\n",x);
    traverse(dstart);
    printf("\n");


    x=delend(&dstart);
    printf("element deleted is %d\n",x);
    traverse(dstart);
    printf("\n");


    p=dstart;
    for(int i=0; i<1; i++){
        p=p->next;
    }
    x=delafter(&p);
    printf("element deleted is %d\n",x);
    traverse(dstart);
    printf("\n");


    p=dstart;
    for(int i=0; i<3; i++){
        p=p->next;
    }
    x=delspecific(&p);
    printf("element deleted is %d\n",x);
    traverse(dstart);
    printf("\n");
    
    
    return 0;
}
 