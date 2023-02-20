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


void inorderTraversal(struct node*t)
{
    if(t!=NULL){
          
        inorderTraversal(t->left);  //LDR
        printf("%d", t->data);
        inorderTraversal(t->right);
    }
}

int height(struct node*t){
    int hl,hr;
    if(t==NULL){
        return 0;
    }
    else{
        if(t->left==NULL && t->right==NULL){
            return 1;
        }
        else{
            hl=height(t->left);
            hr=height(t->right);
            return max(hl,hr)+1;
        }
    }
}

int diameter(struct node*t){
    int d1,d2,d3,m;
    if(t==NULL){
        return 0;
    }
    else{
        d1=height(t->left)+height(t->right)+1;
        d2=diameter(t->left);
        d3=diameter(t->right);
        m=max((max(d1,d2)),d3);
        return m;
    }
}

int main(){
    struct node*root;
    
    root=NULL;  
    root=makenode(1);
    root->left=makenode(2);
    root->left->left=makenode(4);
    
    root->right=makenode(3);
    root->right->right=makenode(5);
    inorderTraversal(root);
    printf("\n");
    printf("%d",diameter(root));
}

