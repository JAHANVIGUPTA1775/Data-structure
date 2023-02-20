#include<iostream>
#include<queue>
#include<stdlib.h>
#include<vector>
using namespace std;

struct node{
    int data;
    struct node *left;
    struct node *right;
    int level;
    
};

struct node*makenode(int x){
    struct node *p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    
    return p;
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


void zigzag(struct node*t){
    queue<struct node*>q;
    int h=height(t);
    vector<int>ht[h+1];
    q.push(t);
    t->level=0;
    ht[t->level].push_back(t->data);
    while(!q.empty()){
        struct node*x=q.front();
        q.pop();
        if(x->left!=NULL){
            q.push(x->left);
            x->left->level=x->level+1;
            ht[x->left->level].push_back(x->left->data);
        }
        if(x->right!=NULL){
            q.push(x->right);
            x->right->level=x->level+1;
            ht[x->right->level].push_back(x->right->data);
        }
    }

    cout<<"zigzag: "<<endl;
    int flag=1;
    for(int i=0;i<=h;i++){
        if(flag%2!=0){
            for(int j=0;j<ht[i].size();j++){
                cout<<ht[i][j]<<" ";
            }
        }
        else{
            for(int j=ht[i].size()-1;j>=0;j--){
                cout<<ht[i][j]<<" ";
            }
        }
        flag++;
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
    
    zigzag(root);
}
