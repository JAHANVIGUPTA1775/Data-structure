#include<iostream>
#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node*next;
};

 struct node*ht[15];

struct node* getnode(){
    struct node*p;
    p= (struct node*)malloc(sizeof(struct node));
    return p;
}


void traverse(struct node *start){
    struct node*p;
    p=start;
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}

void insbeg(struct node**start,int x){
    struct node*p;
    p=getnode();
    p->data=x;
    p->next=*start;
    *start=p;
}

void insend(struct node**start,int x){
    struct node*p,*q;
    q=*start;
    if(q==NULL){
        insbeg(start,x);
    }

    else{
        while(q->next!=NULL){
        q=q->next;
    }
    p=getnode();
    p->data=x;
    p->next=NULL;
    q->next=p;
    }
    
}

void display(){
    for(int i=0;i<=14;i++){
        cout<<i<<": ";
        traverse(ht[i]);
        cout<<endl;
    }
}

int main(){
   
   
    for(int i=0;i<=14;i++){
        ht[i]=NULL;

    }
    int n;
    cout<<"how many data elements";
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int r=x%10;
        insend(&ht[r],x);
    }
    display();
}
