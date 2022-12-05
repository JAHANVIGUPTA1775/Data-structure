#include <iostream>

using namespace std;

int main()
{
    int i,j,k;
    int r1,c1, r2,c2;
    //int sum=0;
   
    cin>>r1>>c1>>r2>>c2;
     int c[r1][c1];
    int a[r1][c1], b[r2][c2];
    for(i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cin>>a[i][j];
        }
    }
    for(i=0; i<r2; i++){
        for(int j=0; j<c2; j++){
            cin>>b[i][j];
        }
    }
    if(r1==r2 && c1==c2){
    for(i=0;i<r1; i++){
        for(j=0; j<c1; j++){
            c[i][j]= a[i][j]- b[i][j];
        }
      
    }
    
    
    for(i=0;i<r1; i++){
        for(j=0; j<c1; j++){
            cout<<c[i][j]<<" ";
        }
      cout<<endl;
    }
    }

    return 0;
}