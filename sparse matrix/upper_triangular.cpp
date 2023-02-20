#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cout<<"enter rows and columns"<<endl;
    cin>>r>>c;
    int matrix[r][c];
    int n=(r*(r+1))/2;
    vector<int>arr;
    int a,b;
    cout<<"enter a b"<<endl;
    cin>>a>>b;
    cout<<"enter matrix"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]!=0){
                arr.push_back(matrix[i][j]);
            }
        }
    }
   
     int m= ((c-3/2)*(a-1))-((a-1)*(a-1)/2)+b-1+1;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<arr[m-1];

}
