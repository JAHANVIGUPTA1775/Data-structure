#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){
    int v,e;
    queue<int>q;
    cout<<"enter num of vertices:";
    cin>>v;
    cout<<"enter num of edges: ";
    cin>>e;
    vector<int>adjlist[v];
    int inDeg[v]={0};
    
    for(int i=1;i<=e;i++){
        int a,b;
        //cout<<"enter end pt of edge "<<i<<":";
        cin>>a>>b;
        adjlist[a].push_back(b);
        
        inDeg[b]++;

    }
   for(int i=0;i<v;i++){
        if(inDeg[i]==0){
            q.push(i);
        }
   }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<adjlist[x].size();i++){
            int a=adjlist[x][i];
            inDeg[a]--;
            if(inDeg[a]==0){
                q.push(a);
            }
        }
        cout<<x<<" ";
    }
}