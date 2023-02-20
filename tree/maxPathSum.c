#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node*makenode(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;

    return p;
}
int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int mps(struct node*t){
    int l,r,m;
    if(t==NULL){
        return 0;
    }
    else{
        if(t->left==NULL && t->right==NULL){
            return t->data;
        }
        else{
            l=mps(t->left);
            r=mps(t->right);
            m=max(l,r);
            return t->data+m;
        }
    }
}
void inorderTraversal(struct node*t)
{
    if(t!=NULL){
          
        inorderTraversal(t->left);  //LDR
        printf("%d", t->data);
        inorderTraversal(t->right);
    }
}



int main(){
    struct node*root;
    
    root=NULL;  
    root=makenode(1);
    root->left=makenode(2);
    root->left->left=makenode(4);
    root->left->right=makenode(5);
    root->right=makenode(3);
    inorderTraversal(root);
    printf("\n");
    printf("%d",mps(root));
}

