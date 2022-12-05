#include<stdio.h>
#include<stdlib.h>
#include"myLL.h"
// struct node{
//     int info;
//     struct node *next;
// };

// struct node* getnode(){
//     struct node*p;
//     p= (struct node*)malloc(sizeof(struct node));
//     return p;
// }

// void traverse(struct node *start){
//     struct node*p;
//     p=start;
//     while(p!=NULL){
//         printf("%d ", p->info);
//         p=p->next;
//     }
// }

// void insbeg(struct node**start,int x){
//     struct node*p;
//     p=getnode();
//     p->info=x;
//     p->next=*start;
//     *start=p;
// }

// void insend(struct node**start,int x){
//     struct node*p,*q;
//     q=*start;
//     if(q==NULL){
//         insbeg(start,x);
//     }

//     else{
//         while(q->next!=NULL){
//         q=q->next;
//     }
//     p=getnode();
//     p->info=x;
//     p->next=NULL;
//     q->next=p;
//     }
    
// }
void reverseInplace(struct node**start){
    struct node*c,*p,*n;
    c=*start;
    p=NULL;
    n=c->next;
    
    while(c!=NULL){
        c->next=p;
        p=c;
        c=n;
        if(n!=NULL){
            n=n->next;
        }
    }
    (*start)=p;
    
    //traverse(start);
}
void addnumbers(struct node**start1,struct node**start2){
    struct node*p,*q,*start3;
    int total,sum,carry=0;
    
    start3=NULL;
    reverseInplace(start1);
    reverseInplace(start2);
    
    p=*start1;
    q=*start2;
    
    
    while(p!=NULL && q!=NULL){
        total=p->info + q->info + carry;
        sum=total%10;
        carry=total/10;
        
        p=p->next;
        q=q->next;
        insbeg(&start3,sum);
    }
    while(p!=NULL){
        total=p->info+carry;
        sum=total%10;
        carry=total/10;
        insbeg(&start3,sum);
        p=p->next;
        
        
    }
    while(q!=NULL){
        total=q->info+carry;
        sum=total%10;
        carry=total/10;
        insbeg(&start3,sum);
        q=q->next;
        
        
    }
    if (carry>0){
        insbeg(&start3,carry);
    }
    traverse(start3);
}

int main(){
    struct node *start1,*start2;
    start1=NULL;
    start2=NULL;
    
    insend(&start1,1);
    insend(&start1,2);
    insend(&start1,8);
    //insend(&start1,4);
    
    insend(&start2,8);
    insend(&start2,5);
    //insend(&start2,3);
    traverse(start1);
    printf("\n");
    traverse(start2);
    printf("\n");
    addnumbers(&start1, &start2);
   
    
}