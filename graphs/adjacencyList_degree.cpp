#include<iostream>
#include<vector>
// #include<pair>
using namespace std;

int main(){
    int v,e;
    cout<<"how many vertices in graph";
    cin>>v;
    cout<<"how many edges in graph";
    cin>>e;
    vector<int>adjlist[v];
    for(int i=1;i<=e;i++){
        int a,b;
        cout<<"enter end points of edge"<<i;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);

    }
    cout<<endl<<"adj list"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<":";
        for(int j=0;j<adjlist[i].size();j++){
            cout<<adjlist[i][j]<<",";
        }
        cout<<endl;
    }
    
  

    cout<<endl<<"degree"<<endl;

    for(int i=0;i<v;i++){
        cout<<i<<":";
        cout<<adjlist[i].size()<<endl;
    }

    




}