#include <iostream>

using namespace std;
int power(int n, int a){
    if(a==0){
        return 1;
    }
    else{
        return n*power(n,a-1);
    }
}

int main()
{
    int n,a;
    cin>>n>>a;
    cout<<power(n,a);

    return 0;
}