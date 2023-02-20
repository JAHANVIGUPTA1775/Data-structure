#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){
    int v,e;
    cout<<"enter num of vertices:";
    cin>>v;
    cout<<"enter num of edges: ";
    cin>>e;
    vector<int>adjlist[v];
    int inDeg[v]={0};
    int outDeg[v]={0};
    for(int i=1;i<=e;i++){
        int a,b;
        cout<<"enter end pt of edge "<<i<<":";
        cin>>a>>b;
        adjlist[a].push_back(b);
        outDeg[a]++;
        inDeg[b]++;

    }
    cout<<"Indegree:"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<":"<<inDeg[i]<<endl;
    }
    cout<<endl<<"outdegree:"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<":"<<outDeg[i]<<endl;
    }
    cout<<endl;
    
}