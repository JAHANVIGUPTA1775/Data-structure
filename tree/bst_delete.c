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

struct node* minimum(struct node*t){
    while(t->left!=NULL){
        t=t->left;
    }
    return t;
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
    //printf("successor is:%d\n", q->data);
    return q;
}

int isleft(struct node*p){
    if(p->parent->left==p){
        return 1;
    }
    else{
        return 0;
    }
}
int isright(struct node*p){
    if(p->parent->right==p){
        return 1;
    }
    else{
        return 0;
    }
}
int issibling(struct node*p){
    if(isleft(p)){
        return p->parent->right;
    }
    else{
        return p->parent->left;
    }
}

int bstdelete(struct node*t,struct node*p){
    struct node*q,*c;
    if(p->left==NULL && p->right==NULL){
        q=p->parent;
        if(q!=NULL){
            if(isleft(p)){
                q->left=NULL;
            }
            else{
                q->right=NULL;
            }
        }
        else{
            t=NULL;
        }
        int x=p->data;
        free(p);
        return x;
    }
    else{
        if(p->left==NULL || p->right==NULL){
            q=p->parent;
            if(p->left==NULL){
                c=p->right;
            }
            else{
                c=p->left;
            }
            if(isleft(p)){
                q->left=c;
            }
            else{
                q->right=c;
            }
            c->parent=q;
            int x=p->data;
            free(p);
            return x;
        }
        else{
            q=bstSuccessor(p);
            int x=bstdelete(t,q);
            int y=p->data;
            p->data=x;
            return y;
        }
    }

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
   struct node*a=bstSearch(root,40);
   printf("deleted elem is %d\n",bstdelete(root,a));
    //inorderTraversal(root);
}

