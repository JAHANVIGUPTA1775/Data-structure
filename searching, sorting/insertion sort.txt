#include <stdio.h>
void insertionsort(int a[], int n){
    for(int i=1;i<n;i++){
        int temp=a[i];
        int j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

int main()
{
    int a[6]={10,1,5,7,6,2};
    int n=6;
    insertionsort(a,n);
    for(int i=0; i<n; i++){
        printf("%d ", a[i]);
    }

    return 0;
}
