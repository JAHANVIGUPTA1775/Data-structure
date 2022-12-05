#include <iostream>
#include<climits>

using namespace std;
int partition(int a[], int low, int high){
    int mid=(low+high)/2;
    int temp = a[low];
    a[low]= a[mid];
    a[mid]= temp;
    int i=low;
    int j=high +1;
    int pivot= a[low];
    do{
        do{
            i++;
        }
        while(a[i]<pivot);
        do{
            j--;
        }
        while(a[j]>pivot);
        if(i<j){
            int t=a[j];
            a[j]= a[i];
            a[i]=t;
        }
    }while(i<j);
        int t= a[j];
        a[j]= a[low];
        a[low]=t;
        return j;
        
}
void quickSort(int a[],int low,int high){
    if(low<high){
        int j= partition( a,  low, high);
        quickSort( a,  low,  j-1);
        quickSort( a,j+1, high);
    }
}



int main()
{
    int a[7]= {9,3,4,2,1,8};
    int low=0;
    int high=5;
    a[6]= INT_MAX;
    
    quickSort(a, low, high);
    for(int i=0; i<6; i++){
        cout<<a[i]<<" ";
    }

    return 0;
}

