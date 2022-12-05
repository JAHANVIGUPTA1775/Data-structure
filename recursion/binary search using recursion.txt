#include <iostream>

using namespace std;
int binarySearch(int a[], int low, int high, int key){
    //int mid;
    if(low<=high){
        int mid=(low+high)/2;
        if(a[mid]==key){
            return mid;
        }
        else{
            if(key<a[mid]){
                binarySearch(a, low, mid-1, key);
            }
            else{
                binarySearch(a, mid+1, high, key);
            }
        }
    }
}

int main()
{
    int a[100], low, high,key;
    int n;
    cin>>n>>key;
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    
    cout<<binarySearch(a, 0, n-1, key)<<endl;
    return 0;
}