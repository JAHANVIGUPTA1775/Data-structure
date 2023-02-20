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

struct node*lca(struct node*t,int x,int y){
    struct node*l,*r;
    if(t==NULL){
        return NULL;
    }
    else{
        if(t->data==x||t->data==y){
            return t;
        }
        else{
            l=lca(t->left,x,y);
            r=lca(t->right,x,y);
            if(l==NULL){
                return r;
            }
            else if(r==NULL){
                return l;
            }
            else{
                return t;
            }
        }
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
    struct node*p=lca(root,4,5);
    printf("\n%d",p->data);

    
}

