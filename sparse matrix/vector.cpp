#include<iostream>
#include<bits/stdc++.h>
using namespace std;


struct vec{
    int row;
    int column;
    int value;
}s[100];

int main(){
    int r,c;
    cout<<"enter rows and columns"<<endl;
    cin>>r>>c;
    int matrix[r][c];
    int k=0;
    cout<<"enter matrix"<<endl;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>matrix[i][j];
            if(matrix[i][j]!=0){
                s[k].row=i;
                s[k].column=j;
                s[k].value=matrix[i][j];
                k++;
            }
        }
    }
    for(int i=0;i<k;i++){
        cout<<s[i].row<<" "<<s[i].column<<" "<<s[i].value<<endl;
    }
   
    

}
