#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    int r,c;
    cout<<"enter rows and columns"<<endl;
    cin>>r>>c;
    int matrix[r][c];
    int n=(r*(r+1))/2;
    int arr[n];
    int a,b;
    cout<<"enter a b"<<endl;
    cin>>a>>b;
    cout<<"enter matrix"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>matrix[i][j];
        }
    }
    
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            int l=(((i+1)*(i))/2)+j+1;
           
           arr[l-1]=matrix[i][j];
           

        }
    }
     int m=(((a+1)*(a))/2)+b+1;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<arr[m-1];

}