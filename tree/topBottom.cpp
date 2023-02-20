#include<iostream>
#include<queue>
#include<stdlib.h>
#include<vector>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
    int hd;
    
};

struct node*makenode(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    
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

void topBottom(struct node*t){
    queue<struct node*>q;
    int h=height(t);
    vector<int>ht[2*h+1];
    q.push(t);
    t->hd=0;
    ht[t->hd+h].push_back(t->data);
    while(!q.empty()){
        struct node*x=q.front();
        q.pop();
        if(x->left!=NULL){
            x->left->hd=x->hd-1;
            q.push(x->left);
            ht[x->left->hd+h].push_back(x->left->data);
        }
        if(x->right!=NULL){
            x->right->hd=x->hd+1;
            q.push(x->right);
            ht[x->right->hd+h].push_back(x->right->data);
        }
    }
    cout<<endl<<"top view of tree is"<<endl;
    for(int i=0;i<2*h+1;i++){
        if(ht[i].size()!=0){
            cout<<ht[i][0]<<" ";
        }
    }
    cout<<endl<<"bottom view of tree is"<<endl;
    for(int i=0;i<2*h+1;i++){
        int x=ht[i].size();
        if(ht[i].size()!=0){
            cout<<ht[i][x-1]<<" ";
        }
    }
    cout<<endl<<"vertical view"<<endl;
    for(int i=0;i<2*h+1;i++){
        for(int j=0;j<ht[i].size();j++){
        cout<<ht[i][j]<<" ";

        }
        
    }
}

int main(){
    struct node*root;
   int x;
    root=NULL;  
    // printf("enter data of root node");
    // scanf("%d",&x);
    // root=makenode(x);
    // createTree(&root);
    root=makenode(40);
    root->left=makenode(20);
    root->left->left=makenode(30);
    root->left->right=makenode(10);
    root->right=makenode(5);
    root->right->right=makenode(4);
    
    topBottom(root);
}
