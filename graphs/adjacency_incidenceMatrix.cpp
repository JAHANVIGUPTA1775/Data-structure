#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(){
    int v,e;
    cout<<"enter num of vertices of graph: ";
    cin>>v;
    cout<<"enter num of edges of graph: ";
    cin>>e;
    vector<int>adjlist[v];
    int m[v][v];
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            m[i][j]=0;
        }
    }
    for(int i=1;i<=e;i++){
        int a,b;
        cout<<"enter end point of edge "<<i<<": ";
        cin>>a>>b;
        
        m[a][b]=1;
        m[b][a]=1;


    }
    cout<<endl<<"adjacency matrix"<<endl;
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            cout<<m[i][j]<<" ";
        }
        cout<<endl;
    }
    
}
// int main(){
//     int v,e;
//     cout<<"enter num of vertices of graph: ";
//     cin>>v;
//     cout<<"enter num of edges of graph: ";
//     cin>>e;
//     vector<int>adjlist[v];
//     int m[v][v];
//     for(int i=0;i<v;i++){
//         for(int j=0;j<v;j++){
//             m[i][j]=0;
//         }
//     }

//     for(int i=1;i<=e;i++){
//         int a,b;
//         cout<<"enter end point of edge "<<i<<": ";
//         cin>>a>>b;
        
//         m[a][i-1]=1;
//         m[b][i-1]=1;


//     }
//      cout<<endl<<"incidence matrix"<<endl;
//     for(int i=0;i<v;i++){
//         for(int j=0;j<v;j++){
//             cout<<m[i][j]<<" ";
//         }
//         cout<<endl;
//     }
    
// }