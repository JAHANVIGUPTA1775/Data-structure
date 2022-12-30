#include <stdio.h>
#include <stdlib.h>
#include<math.h>

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



void inorderTraversal(struct node*t)
{
    if(t!=NULL){
          
        inorderTraversal(t->left);  //LDR
        printf("%d", t->data);
        inorderTraversal(t->right);
    }
}

void mirror(struct node**t){
    struct node*temp;
    if((*t)==NULL){
        return;
    }
    else{
        temp=(*t)->left;
        (*t)->left=(*t)->right;
        (*t)->right=temp;
        mirror(&(*t)->left);
        mirror(&(*t)->right);
    }
    
    
}




int main()
{
    struct node*root;
    root=NULL;  
    

    root=makenode(1);
    root->left=makenode(2);
    root->right=makenode(3);
    root->right->left=makenode(4);
    root->right->right=makenode(5);
    root->right->left->left=makenode(6);
    root->right->left->left->right=makenode(7);

    
    inorderTraversal(root);
    printf("\n");
    mirror(&root);
    inorderTraversal(root);

    return 0;
}