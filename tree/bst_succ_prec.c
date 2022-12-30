#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct node{
    int data;
    struct node*left;
    struct node*right;
    struct node*parent;
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
        struct node*r;
        r=makenode(x);
        if(x<q->data){
            q->left=r;
            r->parent=q;
        }
        else{
            q->right=r;
            r->parent=q;
        }
        
    }

}

struct node* minimum(struct node*t){
    while(t->left!=NULL){
        t=t->left;
    }
    return t;
}
struct node* maximum(struct node*t){
    while(t->right!=NULL){
        t=t->right;
    }
    return t;
}

struct node*bstSearch(struct node*t,int key){
    while(t!=NULL){
        if(t->data==key){
            //printf("%d\n", t->data);
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

struct node* bstSuccessor(struct node*p){
    struct node*q;
    if(p->right!=NULL){
        q=minimum(p->right);
    }
    else{
        q=p->parent;
        while(q!=NULL && q->right==p){
            p=q;
            q=q->parent;
        }
    }
    printf("successor is:%d\n", q->data);
    return q;
}

struct node* bstPredecessor(struct node*p){
    struct node*q;
    if(p->left!=NULL){
        q=maximum(p->left);
        //q=p->parent;
    }
    else{
        q=p->parent;
        while(q!=NULL && q->left==p){
            p=q;
            q=q->parent;
        }
    }
    printf("predecessor is: %d\n", q->data);
    return q;
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
    

   inorderTraversal(root);
   printf("\n");

//    printf("min: %d\n", minimum(root));
//     printf("max: %d\n", maximum(root));
//    printf("%d", bstSearch(root,70));
    struct node*a=bstSearch(root,100);
    
    // printf("%d", bstSuccessor(a));
    // printf("\n");
    //printf(" %d", bstPredecessor(a));
    struct node*s=bstSuccessor(a);
    if(s==NULL){
        printf("succ doesnt exist");
    }
    else{
        printf("%d",s);
    }
    
}

