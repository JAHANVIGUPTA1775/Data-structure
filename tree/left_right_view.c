#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#define queuesize 10
#define TRUE 1
#define FALSE 0

struct node*rear,*front;

int ht[100][100]={0};
struct node{
    int data;
    struct node *left;


    struct node *right;
    //struct node *next;
    int level;
};


struct node*makenode(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    //p->next=NULL;
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


struct queue{
    int rear;
    int front;
    struct node* item[queuesize];
};

void initialize(struct queue *q){
    q->rear=-1;
    q->front =0;
}

int isempty(struct queue *q){
    if((q->rear-q->front +1)==0){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(struct queue *q,struct node* x){
    if(q->rear==queuesize-1){
        printf("queue overflow");
        exit(1);
    }

    q->rear++;
    q->item[q->rear]=x;
}
struct node* dequeue(struct queue *q){
    if(isempty(q)){
        printf("queue underflow");
        exit(1);
    }

    struct node* x=q->item[q->front];
    q->front++;
    return x;
}



// void tbtraversal(struct node*t){
//     struct node*x;
//     initialize();
//     t->hd=0;
//     enqueue(t);
//     insertHT(t);
//     while(!isempty()){
//         x=dequeue();
//         if(x->left!=NULL){
//             x->left->hd=x->hd-1;
//             insertHT(x->left);
//             enqueue(x->left);
//         }
//         if(x->right!=NULL){
//             x->right->hd=x->hd+1;
//             insertHT(x->right);
//             enqueue(x->right);
//         }
//         printf("%d", x->data);
//     }
    
// }
void insertHT(struct node* x){
    int r=x->level;
    int c=0;
    while( ht[r][c]!=0){
        c++;
    }
    ht[r][c]=x->data;

}


int main()
{   
    struct queue q;
    initialize(&q);

    struct node*root,*x;
    int y;
    root=NULL;  

    int R=0;

    printf("enter data of root node");
    scanf("%d",&y);
    root=makenode(y);

    root->level=0;

    createTree(&root);
    enqueue(&q, root);
    insertHT(root);

    printf("Level Order Traversal: ");

    while(!isempty(&q)){
        x=dequeue(&q);
        if(x->left!=NULL){
            x->left->level=x->level+1;
            if(R<x->left->level){
                R=x->left->level;
            }
            enqueue(&q,x->left);
            insertHT(x->left);
            
        }
        if(x->right!=NULL){
            x->right->level=x->level+1;
            R=x->right->level;
            enqueue(&q, x->right);
            insertHT(x->right);
            
        }
        printf("%d", x->data);
    }

    printf("\nLEFT View Traversal: ");
    for(int i=0; i<=R; i++){
        printf("%d", ht[i][0]);
    }

    printf("\nRIGHT View Traversal: ");
    for(int i=0; i<=R;i++){
        int j=0;
        while(ht[i][j]!=0){
            j++;
        }
        printf("%d", ht[i][j-1]);
    }

    return 0;
}