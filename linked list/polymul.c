#include <stdio.h>
#include<stdlib.h>
#include"polynomialLL.h"

// struct node{
//     int coeff;
//     int exponent;
//     struct node *next;
// };



// struct node* getnode(){
//     struct node*p;
//     p= (struct node*)malloc(sizeof(struct node));
//     return p;
// }



// void insbeg(struct node**start,int x,int y){
//     struct node*p;
//     p=getnode();
//     p->coeff=x;
//     p->exponent=y;
//     p->next=*start;
//     *start=p;
// }

// void insend(struct node **start,int x,int y){
//     struct node*p,*q;
//     q=*start;
//     p=getnode();
//     if(q==NULL)
//     {
//         insbeg(start,x,y);
//     }
//     else
//     {
//     while(q->next!=NULL){
//         q=q->next;
//     }
//     p->coeff=x;
//     p->exponent=y;
//     p->next=NULL;
//     q->next=p;
//     }
// }

// void insaft(struct node**q,int x,int y){
//     struct node*p;
//     p=getnode();
//     p->coeff=x;
//     p->exponent=y;
//     p->next= (*q)->next;
//     (*q)->next=p;
// }

// void orderedins(struct node**start, int x,int y){
//     struct node *p, *q;
//     p=*start;
//     q=NULL;
//     while(p!=NULL && y>=p->exponent){
//         q=p;
//         p=p->next;
//     }
//     if(q==NULL){
//         insbeg(start,x,y);
//     }
//     else{
//         insaft(&q,x,y);
//     }

// }

// int delafter(struct node **p){
    

//     int x;
//     struct node*q,*r;
//     q=(*p)->next;
//     r=q->next;
//     (*p)->next=r;
    
//     x=q->coeff;
//     free(q);
//     return x;
// }
// void traverse(struct node*start){
//     struct node*p;
//     p=start;
//     while(p!=NULL){

//         if(p->next==NULL){
//             printf("%dx^%d", p->coeff,p->exponent);
//             p=p->next;
//         }
//         else{
//             printf("%dx^%d+ ", p->coeff,p->exponent);
//             p=p->next;
//         }

        
//     }
// }

void polymul(struct node **poly1,struct node **poly2){
    struct node *q,*poly3,*p;
    poly3=NULL;
    q=*poly2;
    while(q!=NULL){
        p=*poly1;
        while(p!=NULL){
            orderedins(&poly3,p->coeff*q->coeff, p->exponent+q->exponent);
            p=p->next;
        }
        q=q->next;
    }
    p=poly3;
    while(p->next!=NULL){
        if(p->exponent==p->next->exponent){
            p->coeff=p->coeff+p->next->coeff;
            delafter(&p);
        }
        else{
            p=p->next;
        }
    }
    traverse(poly3);
}


int main(){
    struct node*poly1,*poly2,*p;
    poly1=NULL;
    poly2=NULL;
    // insbeg(&start,1,6);
    // insbeg(&start,3,2);
    // insbeg(&start,3,8);
    // insend(&start,5,5);
    
    orderedins(&poly1,1,6);
    orderedins(&poly1,3,2);
    traverse(poly1);
    printf("\n");
    orderedins(&poly2,4,2);
    orderedins(&poly2,3,9);
    traverse(poly2);
    printf("\n");

    polymul(&poly1,&poly2);
    
    return 0;
}