#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int v,e,a,b,w;
    cout<<"How many Vertices? ";
    cin>>v;
    cout<<"How many Edges? ";
    cin>>e;
    vector<pair<int,int>>AdjList[v];
    for(int i=1;i<=e;i++)
    {
        cout<<"Enter the end points of Edge "<<i<<": ";
        cin>>a>>b;
        cout<<"Enter Weight: ";
        cin>>w;
        AdjList[a].push_back(make_pair(b,w));
    }
    cout<<"Adj. List: "<<endl;
    for(int i=0;i<v;i++)
    {
        cout<<i<<": ";
        for(int j=0;j<AdjList[i].size();j++)
        {
            cout<<"("<<AdjList[i][j].first<<","<<AdjList[i][j].second<<")"<<" ";
        }
        cout<<endl;
    }
}