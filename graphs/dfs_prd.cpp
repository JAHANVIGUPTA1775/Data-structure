#include<iostream>
#include<vector>
#include<queue>
// #include<pair>
using namespace std;

void dfs_visit(vector<int>&visited, vector<int>adjlist[],int i,vector<int>&prd){
    cout<<i;
    visited[i]=1;
    for(int j=0;j<adjlist[i].size();j++){
        if(visited[adjlist[i][j]]==0){
            dfs_visit(visited, adjlist,adjlist[i][j],prd);
            prd[adjlist[i][j]]=i;
        }
    }
}

void dfs(vector<int>adjlist[], int v){
    vector<int>prd(v,-1);

    vector<int>visited(v,0);
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            dfs_visit(visited, adjlist,i,prd);  
        }
    }
     cout<<endl<<"predecessor"<<endl;
    //int c=0;
    for(int i=0;i<v;i++){
        cout<<i<<":";
        cout<<prd[i]<<endl;
        // if(prd[i]==-1){
        //     c++;
        // }
    }
    // cout<<"no. of connected components: "<<c<<endl;
}

int main(){
    int v,e;
    cout<<"enter num of vertices:";
    cin>>v;
    cout<<"enter num of edges:";
    cin>>e;
    vector<int>adjlist[v];
    for(int i=1;i<=e;i++){
        int a,b;
        cout<<"enter end points of edge "<<i<<": ";
        cin>>a>>b;
        adjlist[a].push_back(b);
    }
    for(int i=0;i<v;i++){
        cout<<i<<":";
        for(int j=0;j<adjlist[i].size();j++){
            cout<<adjlist[i][j]<<",";
        }
        cout<<endl;
    }
    cout<<endl;
    dfs(adjlist,v);
}