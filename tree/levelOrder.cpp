#include<iostream>
#include<queue>
using namespace std;

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


void levelorder(struct node*t){
    queue<struct node*>q;
    q.push(t);
    while(q.size()!=0){
        struct node*x;
        x=q.front();
        q.pop();
        if(x->left!=NULL){
            q.push(x->left);
        }
        if(x->right!=NULL){
            q.push(x->right);
        }
        cout<<x->data;
    }
}

int main(){
    struct node*root;
    int x;
    root=NULL;  
    // cout<<("enter data of root node")<<endl;
    // cin>>x;
    root=makenode(1);
    root->left=makenode(2);
    root->right=makenode(3);
    root->left->left=makenode(4);
    root->left->right=makenode(5);
    levelorder(root);
    
    return 0;
}