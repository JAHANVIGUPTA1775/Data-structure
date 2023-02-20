#include<iostream>
#include<queue>
using namespace std;

int main(){
    priority_queue<int>maxpq;
    maxpq.push(8);
    maxpq.push(6);
    maxpq.push(4);
    maxpq.push(3);
    maxpq.push(9);
    maxpq.push(1);
    maxpq.push(0);
    maxpq.push(2);
    int x=maxpq.size();
    for(int i=0;i<x;i++){
        cout<<maxpq.top()<<" ";
        maxpq.pop();
    }
    cout<<endl;
    priority_queue<int,vector<int>,greater<int>>minpq;
     minpq.push(8);
    minpq.push(6);
    minpq.push(4);
    minpq.push(3);
    minpq.push(9);
    minpq.push(1);
    minpq.push(0);
    minpq.push(2);
    x=minpq.size();
    for(int i=0;i<x;i++){
        cout<<minpq.top()<<" ";
        minpq.pop();
    }
}