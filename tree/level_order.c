#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define TRUE 1
#define FALSE 0

struct node*rear,*front;
struct node{
    int data;
    struct node *left;
    struct node *right;
    struct node *next;
};


struct node*makenode(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    p->next=NULL;
    return p;
}
void createTree(struct node**t){
    int choice,x;
    struct node*p;
    printf("whether the left of %d exists(1/0)", (*t)->data);
    scanf("%d", &choice);
    if(choice==1){
        printf("input the data of left of %d",(*t)->data);
        scanf("%d",&x);
        p=makenode(x);
        (*t)->left=p;
        createTree(&p);
    }

    printf("whether the right of %d exists(1/0)", (*t)->data);
    scanf("%d", &choice);
    if(choice==1){
        printf("input the data of right of %d",(*t)->data);
        scanf("%d",&x);
        p=makenode(x);
        (*t)->right=p;
        createTree(&p);
    }

}


void preorderTraversal(struct node*t)
{
    if(t!=NULL){
        printf("%d", t->data);  //DLR
        preorderTraversal(t->left);
        preorderTraversal(t->right);
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


void postorderTraversal(struct node*t)
{
    if(t!=NULL){
          
        postorderTraversal(t->left); //LRD
        postorderTraversal(t->right); 
        printf("%d", t->data);
        
    }
}

initialize(){
    rear=NULL;
    front=NULL;
}
enqueue(struct node*p){
    if(rear!=NULL){
        rear->next=p;
    
    }
    else{
        front =p;
    }
    rear=p;
    
}
struct node*dequeue(){
    struct node*p;
    p=front;
    front=front->next;
    if(front==NULL){
        rear=NULL;
    }
    return p;
}

isempty(){
    if((front)==NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
void levelordertraversal(struct node*t){
    struct node*p;
    initialize();
    enqueue(t);
    while(!isempty()){
        p=dequeue();
        printf("\t%d", p->data);
        if(p->left!=NULL){
            enqueue(p->left);
        }
        if(p->right!=NULL){
            enqueue(p->right);
        }

    }
}


int main()
{
    struct node*root;
    int x;
    root=NULL;  
    printf("enter data of root node");
    scanf("%d",&x);
    root=makenode(x);
    createTree(&root);
    
    levelordertraversal(root);
    printf("\n");
    return 0;
}