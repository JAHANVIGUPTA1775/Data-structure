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
int countNodes(struct node*t){
    if(t==NULL){
        return 0;
    }
    else{
        return 1+countNodes(t->left)+countNodes(t->right);
    }
}

int arr[100]={9999};
int i=0;
void inorderTraversal(struct node*t){
    if(t!=NULL){
        inorderTraversal(t->left);
        //printf("%d ", t->data);
        arr[i]=t->data;
        i++;
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


int main(){
   struct node*root;
   root=NULL;
//    bstInsert(&root,100);
//    bstInsert(&root,50);
//    bstInsert(&root,130);
//    bstInsert(&root,20);
//    bstInsert(&root,70);
//    bstInsert(&root,40);
//    bstInsert(&root,150);

   root=makenode(100);
    root->left=makenode(50);
    root->right=makenode(130);
    root->right->left=makenode(220);
    root->right->right=makenode(70);
    root->right->left->left=makenode(40);
    root->right->left->left->right=makenode(150);
    int flag=0;
    int n=countNodes(root);
   inorderTraversal(root);
   printf("\n");
   for(int i=0; i<n;i++){
    if(arr[i]<arr[i+1]){
        flag=1;
    }
    else{
        flag=0;
        break;
    }
   }
   if(flag==1){
    printf("yes");
   }
   else{
    printf("no");
   }
}