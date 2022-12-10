#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *left;
    struct node *right;
};

struct node*makenode(char x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;

    return p;
}

void preorderTraversal(struct node*t)
{
    if(t!=NULL){
        printf("%c", t->data);  //DLR
        preorderTraversal(t->left);
        preorderTraversal(t->right);
    }
}

void inorderTraversal(struct node*t)
{
    if(t!=NULL){
          
        inorderTraversal(t->left);  //LDR
        printf("%c", t->data);
        inorderTraversal(t->right);
    }
}


void postorderTraversal(struct node*t)
{
    if(t!=NULL){
          
        postorderTraversal(t->left); //LRD
        postorderTraversal(t->right); 
        printf("%c", t->data);
        
    }
}


int main()
{
    struct node*root;
    root=NULL;

    root=makenode('A');
    root->left=makenode('B');
    root->right=makenode('C');
    root->right->left=makenode('E');
    root->right->right=makenode('F');
    root->right->left->left=makenode('G');
    root->right->left->left->right=makenode('H');
    

    preorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);

    return 0;
}