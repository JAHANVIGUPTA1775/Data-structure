#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct node{
    int row;
    int column;
    int value;
    struct node* next;
};

struct node* getnode(){
    struct node*p;
    p= (struct node*)malloc(sizeof(struct node));
    return p;
}

void traverse(struct node *start){
    struct node*p;
    p=start;
    while(p!=NULL){
        printf("%d %d %d\n", p->row, p->column,p->value);
        p=p->next;
    }
}

void insbeg(struct node**start,int x,int r, int c){
    struct node*p;
    p=getnode();
    p->row=r;
    p->column=c;
    p->value=x;
    p->next=*start;
    *start=p;
}

void insend(struct node**start,int x,int r, int c){
    struct node*p,*q;
    q=*start;
    if(q==NULL){
        insbeg(start,x,r,c);
    }

    else{
        while(q->next!=NULL){
        q=q->next;
    }
    p=getnode();
    p->row=r;
    p->column=c;
    p->value=x;
    p->next=NULL;
    q->next=p;
    }
    
}
void insaft(struct node **q, int x,int r,int c){
    struct node *p,*t;
    p=getnode();
    p->row=r;
    p->column=c;
    p->value=x;
    t=(*q)->next;  //p->next=q->next;
    p->next=t;     //q->next=p;
    (*q)->next=p;
}

void orderedIns(struct node** start, int x,int r,int c){
    struct node *p, *q;
    p=(*start);
    q=NULL;
    while(p!=NULL && x>=p->value){
        q=p;
        p=p->next;
    }
    if (q==NULL){
        insbeg(start,x,r,c);
    }
    else{
        insaft(&q,x,r,c);
    }
}

int main(){
    int r,c;
    cout<<"enter rows and columns"<<endl;
    cin>>r>>c;
    int matrix[r][c];
    struct node*start=NULL;
    cout<<"enter matrix"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]!=0){
                
                    orderedIns(&start,matrix[i][j],j,i);
               
               
            }
        }
    }
    traverse(start);
   
    

}
