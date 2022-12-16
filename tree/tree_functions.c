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

int countNodes(struct node*t){
    if(t==NULL){
        return 0;
    }
    else{
        return 1+countNodes(t->left)+countNodes(t->right);
    }
}
int countLeaf(struct node*t){
    if(t==NULL){
        return 0;
    }
    else{
        if(t->left==NULL && t->right==NULL){
            return 1;
        } 
        else{
            return countLeaf(t->left)+countLeaf(t->right);
        }
    }
}

int countN2(struct node*t){
    if(t==NULL){
        return 0;
    }
    else{
        if(t->left==NULL && t->right==NULL){
            return 0;
        } 
        else{
            if(t->left!=NULL && t->right!=NULL){
            return 1+countN2(t->left)+countN2(t->right);
            
            } 
            else{
                return countN2(t->left)+countN2(t->right);
            }
        }
    }
}

int countN1(struct node*t){
    if(t==NULL){
        return 0;
    }
    else{
        if(t->left==NULL && t->right==NULL){
            return 0;
        } 
        else{
            if(t->left!=NULL && t->right!=NULL){
            return countN1(t->left)+countN1(t->right);
            
            } 
            else{
                return 1+countN1(t->left)+countN1(t->right);
            }
        }
    }
}

int max(int a,int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int height(struct node*t){
    if(t==NULL){
        return 0;
    }
    else{
        if(t->left==NULL && t->right==NULL){
            return 0;
        } 
        else{
            return max((height(t->left)), height(t->right))+1;
        }
    }
}

void isStrictlyBinary(struct node*t){
    int n=countN1(t);
    if(n==0){
        printf("yes, it is strictly binary");
    }
    else{
        printf("no, it is not strictly binary");
    }
}

int sumofallnodes(struct node*t){
    if(t==NULL){
        return 0;
    }
    else{
        return t->data+sumofallnodes(t->left)+sumofallnodes(t->right);
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
    

    preorderTraversal(root);
    printf("\n");
    inorderTraversal(root);
    printf("\n");
    postorderTraversal(root);
    printf("\n");

    printf("countNodes: %d\n",countNodes(root));
    printf("countLeaf: %d\n",countLeaf(root));
    printf("countN2: %d\n",countN2(root));
    printf("countN1: %d\n",countN1(root));
    printf("height: %d\n",height(root));

    isStrictlyBinary(root);
    printf("\n");
    printf("sumofallnodes: %d\n",sumofallnodes(root));

    return 0;
}