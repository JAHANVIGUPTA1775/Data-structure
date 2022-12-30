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
int search(int in[], int start, int end, int x){
    for(int i=start;i<=end; i++){
        if(in[i]==x){
            return i;
        }
    }
}


struct node* buildtree(int in[], int pre[], int start, int end){
    static int preIndex=0;
    if(start>end){
        return NULL;
    }
    struct node*p;
    p=makenode(pre[preIndex]);
    preIndex++;
    if(start==end){
        return p;
    }
    int sindex=search(in,start,end,p->data);
    p->left=buildtree(in,pre,start, sindex-1);
    p->right=buildtree(in,pre,sindex+1, end);
    return p;
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



int main()
{
    struct node*root;
    root=NULL;  
    
    int pre[7]={1,2,5,3,4,7,6};
    int in[7]={5,2,1,4,7,3,6};

    int start=0;
    int end=6;
    root= buildtree(pre,in,start,end);

    inorderTraversal(root);
    printf("\n");
    preorderTraversal(root);
    return 0;
}