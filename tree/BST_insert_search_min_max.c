#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
};

struct node*makenode(int x){
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

void inorderTraversal(struct node*t){
    if(t!=NULL){
        inorderTraversal(t->left);
        printf("%d ", t->data);
        inorderTraversal(t->right);
    }
}

void bstInsert(struct node**t, int x){
    struct node*p,*q;
    p=*t;
    q=NULL;
    if(*t==NULL){
        *t=makenode(x);
    }
    else{
        while(p!=NULL){
            q=p;
            if(x<p->data){
                p=p->left;
            }
            else{
                p=p->right;
            }
        }
        if(x<q->data){
            q->left=makenode(x);
        }
        else{
            q->right=makenode(x);
        }
    }

}

int minimum(struct node*t){
    while(t->left!=NULL){
        t=t->left;
    }
    return t->data;
}
int maximum(struct node*t){
    while(t->right!=NULL){
        t=t->right;
    }
    return t->data;
}

struct node*bstSearch(struct node*t,int key){
    while(t!=NULL){
        if(t->data==key){
            printf("%d\n", t->data);
            return t;
        }
        else{
            if(key<t->data){
                t=t->left;
            }
            else{
                t=t->right;
            }
        }
    }
    return NULL;
}


int main(){
   struct node*root;
   root=NULL;
   bstInsert(&root,100);
   bstInsert(&root,50);
   bstInsert(&root,130);
   bstInsert(&root,20);
   bstInsert(&root,70);
   bstInsert(&root,40);
   bstInsert(&root,150);
    // int t;
    // printf("enter num of nodes: ");
    // scanf("%d",&t);
    // while(t--){
    //     int x;
    //     scanf("%d", &x);
    //     bstInsert(&root,x);
    // }

   inorderTraversal(root);
   printf("\n");
   printf("min: %d\n", minimum(root));
    printf("max: %d\n", maximum(root));
    printf("%d", bstSearch(root,70));

}

