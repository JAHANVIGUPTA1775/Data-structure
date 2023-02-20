#include<iostream>
#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>ipair;

int main(){
    int v,e;
    cout<<"enter no of vertices"<<endl;
    cin>>v;
    vector<pair<int,int>>adj[v];
    cout<<"enter no of edges"<<endl;                                                                                                            
    cin>>e;

    for(int i=1;i<=e;i++){
        int a,b,cost;
        cout<<"enter end points of edge and cost"<<i<<": ";
        cin>>a>>b>>cost;
        adj[a].push_back({b,cost});
        adj[b].push_back({a,cost});
    }
   
    for(int i=0;i<v;i++){
        int j=0;cout<<i<<": ";
        for(int j=0;j<adj[i].size();j++){
            cout<<"("<<adj[i][j].first<<",";
            cout<<adj[i][j].second<<"), ";
        }
        cout<<endl;
    }


vector<int>inmst(v,0);
vector<int>key(v,INT_MAX);
vector<int>pred(v,-1);
key[0]=0;

priority_queue<ipair, vector<ipair>, greater<ipair>>pq;

pq.push({0,0});  //key,vertex

for(int i=1;i<=v-1;i++){
    pq.push({INT_MAX,i});
}

for(int i=1;i<=v-1;i++){
    pair<int,int>x=pq.top();  //key,vertex
    pq.pop();

    int n=x.second;
    inmst[n]=1;
    for(int j=0;j<adj[n].size();j++){

        int vertex=adj[n][j].first;
        int weight=adj[n][j].second;
        if(inmst[vertex]==0 && key[vertex]>weight){
            key[vertex]=weight;
            pred[vertex]=n;

            pq.push({key[vertex], vertex});
        }
    }
}
cout<<"mst is"<<endl;
cout<<"vertex  key "<<"predecessor"<<endl;
for(int i=0;i<v;i++){
    cout<<i<<"\t";
    cout<<key[i]<<"\t";
    cout<<pred[i];
    cout<<endl;
}

}
