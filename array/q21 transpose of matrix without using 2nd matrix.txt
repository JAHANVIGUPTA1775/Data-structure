#include <iostream>

using namespace std;

int main()
{
    int i,j;
    int r1,c1;
    cin>>r1>>c1;
    
    int a[r1][c1], b[r1][c1];
    int temp[r1][c1];
    for(i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cin>>a[i][j];
        }
    }
    
    for(i=0; i<r1; i++){
        for(int j=0; j<c1; j++){ //j<i
            if(i<j){
               int temp= a[i][j];
                a[i][j]= a[j][i];
                a[j][i]= temp;
            }
        }
      
    }
    for(i=0; i<r1; i++){
        for(int j=0; j<c1; j++){
            cout<<a[i][j]<<" ";
        }
      cout<<endl;
    }
    
    return 0;
}