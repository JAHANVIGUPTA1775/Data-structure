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

void addsparsematrix(struct node*list1,struct node*list2){
    struct node*list3=NULL;
    struct node*p=list1;
    struct node*q=list2;
    while(p!=NULL && q!=NULL){
        if(p->row==q->row){
            if(p->column==q->column){
                insend(&list3,p->value+q->value,p->row,p->column);
                p=p->next;
                q=q->next;
            }
            else{
                if(p->column<q->column){
                    insend(&list3,p->value,p->row,p->column);
                    p=p->next;
                }
                else{
                    insend(&list3,q->value,q->row,q->column);
                    q=q->next;
                }
            }
        }
        else{
            if(p->row<q->row){
                insend(&list3,p->value,p->row,p->column);
                p=p->next;
            }
            else{
                insend(&list3,q->value,q->row,q->column);
                q=q->next;
            }
        }
    }
    while(p!=NULL){
        insend(&list3,p->value,p->row,p->column);
        p=p->next;
    }
    while(q!=NULL){
        insend(&list3,q->value,q->row,q->column);
        q=q->next;
    }

    traverse(list3);
}

int main(){
    int r,c;
    cout<<"enter rows and columns"<<endl;
    cin>>r>>c;
    int matrix1[r][c];
    int matrix2[r][c];
    struct node*start1=NULL;
    struct node*start2=NULL;
    cout<<"enter matrix 1"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>matrix1[i][j];
            if(matrix1[i][j]!=0){
                if(start1==NULL){
                    insbeg(&start1,matrix1[i][j],i,j);
                }
                else{
                    insend(&start1,matrix1[i][j],i,j);
                }
               
            }
        }
    }
    cout<<"enter matrix 2"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>matrix2[i][j];
            if(matrix2[i][j]!=0){
                if(start2==NULL){
                    insbeg(&start2,matrix2[i][j],i,j);
                }
                else{
                    insend(&start2,matrix2[i][j],i,j);
                }
               
            }
        }
    }
    addsparsematrix(start1,start2);
   
    

}
