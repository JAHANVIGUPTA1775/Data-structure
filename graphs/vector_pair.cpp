#include<iostream>
#include<vector>
// #include<pair>
using namespace std;

int main(){
//    vector<int>v(5,2);

//    cout<<"capacity "<<v.capacity()<<endl;
//    cout<<"size "<<v.size()<<endl;
//    v.push_back(10);
//    cout<<"capacity "<<v.capacity()<<endl;
//    cout<<"size "<<v.size()<<endl;
//     for(auto i:v){
//         cout<<i<<" ";
//     }


// vector<pair<int,int>>v;
// v.push_back(make_pair(1234,98));
// v.push_back(make_pair(2345,96));
// v.push_back(make_pair(3456,88));

//    cout<<"capacity "<<v.capacity()<<endl;
//    cout<<"size "<<v.size()<<endl;

// for(int j=0;j<v.size();j++){
//     cout<<v[j].first;
//     cout<<","<<v[j].second<<endl;
// }

vector<int>v[3];
v[0].push_back(1);
v[0].push_back(2);
v[0].push_back(3);

v[1].push_back(4);
v[1].push_back(5);

v[2].push_back(6);
v[2].push_back(7);
v[2].push_back(8);
v[2].push_back(9);

for(int i=0;i<v[i].size();i++){
    cout<<i<<":";
    for(int j=0;j<v[i].size();j++){
        cout<<v[i][j]<<",";
    }
    cout<<endl;
}




}