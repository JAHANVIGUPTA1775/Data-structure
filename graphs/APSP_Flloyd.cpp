#include<iostream>
#include<climits>
using namespace std;
int w[100][100];
 int D[100][100]={0};

void APSP(int n){
   
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(w[i][j]==0){
                if(i!=j){
                    D[i][j]=INT_MAX/2;
                }
            }
            else{
                D[i][j]=w[i][j];
            }
        }
    }
    for(int k=1; k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int x=D[i][j];
                int y=D[i][k]+D[k][j];
                D[i][j]=min(x,y);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int v,e;
    cout<<"enter no of vertices"<<endl;
    cin>>v;
    cout<<"enter no of edges"<<endl;
    cin>>e;
    int a=0;
    // int adjmatrix[v][v];
    // for(int i=0;i<v;i++){
    //     for(int j=0;j<v;j++){
    //         adjmatrix[i][j]=0;
    //     }
    // }

    
    for(int i=1;i<=v;i++){
        for(int j=1;j<=v;j++){
            cout<<"enter the weight of edge "<<i<<" "<<j<<":";
            cin>>a;
            w[i][j]=a;
        }
    }
    for(int i=1;i<=v;i++){
        for(int j=1; j<=v;j++){
            cout<<w[i][j];
        }
        cout<<endl;
    }
    APSP(v);
    


}
