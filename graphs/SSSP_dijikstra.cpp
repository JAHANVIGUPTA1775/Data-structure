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
        //adj[b].push_back({a,cost});
    }
   
    for(int i=0;i<v;i++){
        int j=0;cout<<i<<": ";
        for(int j=0;j<adj[i].size();j++){
            cout<<"("<<adj[i][j].first<<",";
            cout<<adj[i][j].second<<"), ";
        }
        cout<<endl;
    }


vector<int>inpq(v,1);
vector<int>distance(v,INT_MAX);
vector<int>pred(v,-1);


priority_queue<ipair, vector<ipair>, greater<ipair>>pq;
int source;

cout<<endl<<"enter source vertex: ";
cin>>source;

pq.push({0,source});  
distance[source]=0;

for(int i=0;i<v && i!=source ;i++){
    pq.push({INT_MAX,i});
}

for(int i=1;i<=v-1;i++){
    pair<int,int>x=pq.top();  //key,vertex
    pq.pop();

    int n=x.second;
    inpq[n]=0;
    for(int j=0;j<adj[n].size();j++){

        int vertex=adj[n][j].first;
        int weight=adj[n][j].second;
        if(inpq[vertex]==1 && distance[vertex]>weight+distance[n]){
            distance[vertex]=weight+distance[n];
            pred[vertex]=n;

            pq.push({distance[vertex], vertex});
        }
    }
}
cout<<"shortest path is"<<endl;
cout<<"vertex  disatnce "<<"predecessor"<<endl;
for(int i=0;i<v;i++){
    cout<<i<<"\t";
    cout<<distance[i]<<"\t";
    cout<<pred[i];
    cout<<endl;
}

}
