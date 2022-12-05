#include <iostream>

using namespace std;

int main()
{
    int i,j;
    int r1,c1;
    cin>>r1>>c1;
    
    int a[r1][c1], b[r1][c1];
    for(i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cin>>a[i][j];
        }
    }
    
    for(i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            b[i][j]=a[j][i];
        }
      
    }
    for(i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cout<<b[i][j]<<" ";
        }
      cout<<endl;
    }
    
    return 0;
}