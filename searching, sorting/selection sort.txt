#include <stdio.h>

void selectionsort(int a[], int n){
    int min,t;
    for(int i=0; i<n-1; i++){
        min=i;
        for(int j=i+1; j<n; j++){
            if(a[j]<a[min]){
                min=j;
            }
        }
        //swaping
        t=a[i];
        a[i]=a[min];
        a[min]=t;
    }
}

int main()
{
    int arr[6]={5,3,1,7,9,2};
    int n=6;
    
    selectionsort(arr,n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
