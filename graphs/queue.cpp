#include<iostream>
#include<vector>
#include<queue>
// #include<pair>
using namespace std;

int main(){
    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    cout<<q.size()<<endl;
    
    cout<<q.empty()<<endl;

    cout<<q.front()<<endl;
    q.pop();
    cout<<q.front()<<endl;




}