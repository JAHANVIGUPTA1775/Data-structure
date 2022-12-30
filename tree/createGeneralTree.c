#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

struct node{
    char data;
    struct node*child;
    struct node*sibling;
    
};

struct node*makenode(int x){
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->child=NULL;
    p->sibling=NULL;
    return p;
}

void createGTree(struct node**t){
    int choice,x;
    struct node*p;
    printf("whether the child of %d exists(1/0)", (*t)->data);
    scanf("%d", &choice);
    if(choice==1){
        printf("input the data of child of %d",(*t)->data);
        scanf("%d",&x);
        p=makenode(x);
        (*t)->child=p;
        createGTree(&p);
    }

    printf("whether the sibling of %d exists(1/0)", (*t)->data);
    scanf("%d", &choice);
    if(choice==1){
        printf("input the data of sibling of %d",(*t)->data);
        scanf("%d",&x);
        p=makenode(x);
        (*t)->sibling=p;
        createGTree(&p);
    }

}
int main(){
    struct node*root;
    int x;
    root=NULL;  
    printf("enter data of root node");
    scanf("%d",&x);
    root=makenode(x);
    createGTree(&root);

}

