#include<iostream>
using namespace std;

int main(){
    int v,e;
    cout<<"enter no of vertices"<<endl;
    cin>>v;
    cout<<"enter no of edges"<<endl;
    cin>>e;
    int adjmatrix[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            adjmatrix[i][j]=0;
        }
    }

    
    for(int i=1;i<=e;i++){
        int a,b;
        cout<<"enter end points of edge "<<i<<": ";
        cin>>a>>b;
        adjmatrix[a][b]=1;
    }

    for(int k=0;k<v;k++){
        for(int i=0;i<v;i++){
            for(int j=0;j<v;j++){
                adjmatrix[i][j]=adjmatrix[i][j]||(adjmatrix[i][k]&& adjmatrix[k][j]);
            }
        }
    }
    cout<<"transitive closure"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<adjmatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
