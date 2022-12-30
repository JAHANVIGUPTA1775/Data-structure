#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
    //struct node*h;
    int h;
};

struct node*makenode(int x){
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->h=0;
    return p;
}

void inorderTraversal(struct node*t){
    if(t!=NULL){
        inorderTraversal(t->left);
        printf("%d ", t->data);
        inorderTraversal(t->right);
    }
}

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}



int height(struct node*t){
    int hl,hr;
    if(t==NULL){
        return 0;
    }
    if(t->left==NULL){
        hl= 0;
    }
    else{
        hl= 1+t->left->h;
    }
    if(t->right==NULL){
        hr= 0;
    }
    else{
        hr= 1+t->right->h;
    }
    return max(hl,hr);
    
}

struct node* bstInsert(struct node*t, int x){
    if((t)==NULL){
        (t)=makenode(x);
    }
    else{
        if(x<(t)->data){
            (t)->left=bstInsert((t)->left,x);
            
        }
        else{
            (t)->right=bstInsert((t)->right,x);
            
        }
    }
    (t)->h=height(t);
    return t;
}

int main(){
    struct node*root;
   root=NULL;
   root=bstInsert(root,100);
   root=bstInsert(root,50);
   root=bstInsert(root,40);
   root=bstInsert(root,70);
   root=bstInsert(root,150);
   root=bstInsert(root,60);
   

   inorderTraversal(root);
   printf("\n");
}