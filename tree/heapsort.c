#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0

void maxheapify(int a[],int i,int n){
    int l=0,r=0;
    while(2*i<=n){
        l=2*i;
        r=2*i+1;
        int m=l;
        if(r<=n){
            if(a[r]>a[l]){
                m=r;
            }
        }
        if(a[m]>a[i]){
            int temp=a[m];
            a[m]=a[i];
            a[i]=temp;
        }
        else{
            break;
        }
    i=m;
    }
}
void buildmaxheap(int a[],int n){
    for(int i=n/2;i>=1;i--){
        maxheapify(a,i,n);
    }
}

void heapsort(int a[],int n){
    buildmaxheap(a,n);
    for(int j=n;j>=2;j--){
        int temp=a[1];
        a[1]=a[j];
        a[j]=temp;
        maxheapify(a,1,j-1);
    }
}
int main(){
    int a[11]={-1,6,1,2,8,0,5,10,19,3,4};
    heapsort(a,10);
    for(int i=1;i<=10;i++){
        printf("%d ",a[i]);
    }
}

