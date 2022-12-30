#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define TRUE 1
#define FALSE 0

struct node*rear,*front;

struct node{
    int data;
    int level;
    struct node *left;
    struct node *right;
    struct node*next;
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
    printf("whether left of %d exists (1/0): ",(*t)->data);
    scanf("%d", &choice);
    if(choice==1){
        printf("enter data of left of %d: ", (*t)->data);
        scanf("%d", &x);
        p=makenode(x);
        (*t)->left=p;
        createTree(&p);
    }

    printf("whether right of %d exists (1/0): ",(*t)->data);
    scanf("%d", &choice);
    if(choice==1){
        printf("enter data of right of %d: ", (*t)->data);
        scanf("%d", &x);
        p=makenode(x);
        (*t)->right=p;
        createTree(&p);
    }

}
void initialize(){
    rear=NULL;
    front=NULL;
}

void enqueue(struct node*t){
    if(rear!=NULL){
        rear->next=t;
        rear=t;
    }
    else{
        front =t;
        rear=t;
    }
}

struct node*dequeue(){
    struct node*p;
    p=front;
    front=front->next;
    if(front ==NULL){
        rear=NULL;
    }
    return p;
}
isempty(){
    if(front==NULL){
        return TRUE;
    }
    else{
        return FALSE;
    }
}

void insertht(int ht[10][10],struct node* x){
    int r=x->level;
    int c=0;
    while(ht[r][c]!=0){
        c++;
    }
    ht[r][c]=x->data;
}

void sideviewTraversal(struct node*t){
    //queue();
    initialize();
    int ht[10][10]={0};
    (t)->level=0;
    int r=0;
    enqueue(t);
    insertht(ht,t);
    while(!isempty()){
        struct node*x;
        x=dequeue();
        if(x->left!=NULL){
            x->left->level=x->level+1;
            if(r<x->left->level){
                r=x->left->level;
            }
            enqueue(x->left);
            insertht(ht,x->left);
        }

        if(x->right!=NULL){
            x->right->level=x->level+1;
            
            if(r<x->right->level){
                r=x->right->level;
            }
            
            enqueue(x->right);
            insertht(ht,x->right);
        }
    }

    printf("\nleft view traversal\n");
    for(int i=0; i<=r; i++){
        printf("%d ", ht[i][0]);
    }

    printf("\nright view traversal\n");
    for(int i=0; i<=r; i++){
        int j=0;
        while(ht[i][j]!=0){
            j++;
        }
        printf("%d ", ht[i][j-1]);
    }

}



int main(){
    struct node*root;
    root=NULL;
    int x;
    printf("enter root data ");
    scanf("%d", &x);
    root=makenode(x);
    createTree(&root);

    sideviewTraversal(root);
}

