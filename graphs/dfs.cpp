#include<iostream>
#include<vector>
#include<queue>
// #include<pair>
using namespace std;




void dfs_visit(int i,vector<int>&visited,vector<int>adjlist[]){
    cout<<i;
    visited[i]=1;
    for(int j=0;j<adjlist[i].size();j++){
        if(visited[adjlist[i][j]]==0){
            dfs_visit(adjlist[i][j],visited,adjlist);
        }
    }
}

void dfs(vector<int>adjlist[],int v){
    vector<int>visited(v,0);
    for(int i=0;i<v;i++){
        if(visited[i]==0){
            dfs_visit(i,visited,adjlist);
        }
    }
    
    
}

int main(){
    int v,e;
    cout<<"how many vertices in graph";
    cin>>v;
    cout<<"how many edges in graph";
    cin>>e;
    vector<int>adjlist[v];
    for(int i=1;i<=e;i++){
        int a,b;
        cout<<"enter end points of edge"<<i<<":";
        cin>>a>>b;
        adjlist[a].push_back(b);

    }
    cout<<endl<<"adj list"<<endl;
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