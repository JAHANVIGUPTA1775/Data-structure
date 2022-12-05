#include <stdio.h>

void bubblesort(int a[], int n){
    for(int i=0; i<n-1; i++){   //for number of pass
        for(int j=0; j<n-i-1; j++){   //for comparison in each pass
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}
void bubblesortAdaptive(int a[], int n){
    int isSorted=0;
    for(int i=0; i<n-1; i++){
        printf("working on pass number %d\n", i+1);
        isSorted=1;
        for(int j=0; j<n-i-1; j++){
            if(a[j]>a[j+1]){
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                isSorted=0;
            }
        }
        if(isSorted){
            return;
        }
    }
}

int main()
{
    int arr[6]={5,3,1,7,9,2};
    int n=6;
    
    bubblesort(arr,n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}
