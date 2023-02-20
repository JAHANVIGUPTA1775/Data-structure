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
    
    // for(int i=0;i<r;i++){
    //     for(int j=0;j<c;j++){
    //         int l=2*(i+1)+(j+1)-2;
           
    //        arr[l-1]=matrix[i][j];
           

    //     }
    // }
     int m=2*(a+1)+(b+1)-2;
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl<<arr[m-1];

}

// 6 6
// 2 4
// 1 2 0 0 0 0
// 1 2 3 0 0 0
// 0 2 3 4 0 0
// 0 0 3 4 5 0
// 0 0 0 4 5 6
// 0 0 0 0 5 6