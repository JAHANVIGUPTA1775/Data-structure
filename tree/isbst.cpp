#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node*makenode(int x){
    struct node*p;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->left=NULL;
    p->right=NULL;
    return p;
}

int count(struct node*t){
    if(t==NULL){
        return 0;
    }
    else{
        return 1+count(t->left)+count(t->right);
    }
    
}

int i=0;
void inorder(struct node*t,int *arr){
    if(t!=NULL){
        
        inorder(t->left,arr);
        //printf("%d ", t->data);
        arr[i]=(t->data);
        i++;
        inorder(t->right,arr);
    }
    
}



void isbst(struct node*t,int *arr,int n){
    if(t==NULL){
        cout<<"bst"<<endl;
        
    }
    else{
        int flag=0;
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
    cout<<("yes");
   }
   else{
    cout<<("no");
   }
    }
}



int main(){
    struct node *root=NULL;
    root=makenode(7);
    root->left=makenode(3);
    root->left->left=makenode(1);
    root->left->right=makenode(4);
    root->right=makenode(9);
    root->right->left=makenode(8);
   
   
    
    //isbst(root);
    int n=count(root);
    int arr[n];
    inorder(root,arr);
    
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    isbst(root,arr,n);
    
        
}