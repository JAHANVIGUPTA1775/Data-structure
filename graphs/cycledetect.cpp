#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int vertexvisit(vector<int>adj[], vector<int>&status, int i){
    if(status[i]==true){
        return true;
    }
    status[i]=true;
    int flag=false;
    for(int j=0;j<adj[i].size();j++){
        flag=vertexvisit(adj,status,adj[i][j]);
        if(flag==1){
            return true;
        }
    }
    return false;
}

int cycledetect(vector<int>adj[],int n){
    int check=false;
    vector<int>status(n,0);
    for(int i=0;i<n;i++){
        status[i]=true;
        for(int j=0;j<adj[i].size();j++){
            check=vertexvisit(adj,status,i);
            if(check==1){
                return true;
            }
        }
        status[i]=false;
    }
    return false;
}

int main(){
    int n,e;
    cout<<"enter no of vertices"<<endl;
    cin>>n;
    vector<int>adj[n];
    cout<<"enter no of edges"<<endl;
    cin>>e;

    for(int i=1;i<=e;i++){
        int a,b;
        cout<<"enter end points of edge "<<i<<": ";
        cin>>a>>b;
        adj[a].push_back(b);
        //adj[b].push_back({a,cost});
    }
   
    for(int i=0;i<n;i++){
        int j=0;
        cout<<i<<": ";
        for(int j=0;j<adj[i].size();j++){
            
            cout<<adj[i][j]<<", ";
        }
        cout<<endl;
    }

    int check= cycledetect(adj,n);
    if(check==1){
        cout<<"a cycle exists in graph";
    }
    else{
        cout<<"cycle doesn't exists";
    }


}
