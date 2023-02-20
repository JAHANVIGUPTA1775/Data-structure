#include<iostream>
#include<bits/stdc++.h>
using namespace std;


int main(){
   vector<int>ht[15];
   int n;
   cout<<"how many data elements are to be stored";
   cin>>n;
   for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    int r=x%10;
    ht[r].push_back(x);
   }

  for(int i=0;i<n;i++){
        cout<<i<<":";
        for(int j=0;j<ht[i].size();j++){
            cout<<ht[i][j]<<",";
        }
        cout<<endl;
    }

}
