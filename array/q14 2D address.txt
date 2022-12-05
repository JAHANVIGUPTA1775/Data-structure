#include <stdio.h>

int main()
{
    int i;
    // int arr[10]= {1,2,3,4,5,6,7,8,9,10};
    // printf("%u\n", arr);
    // printf("%u\n", &arr[4]);
    // int x=(4-0);
    // printf("%d", arr+x);
    
    int a[4][5];
    int i=2, j=3, x;
    printf("\n%u", a[0]);
    printf("\n%u", &a[2][3]);
    x= (i-0)*(4-0+1)+(j-0);
    printf("\n%d", x);
    printf("\n%u", a[0]+x);
   
    // int a[4][5][6];
    // int i=2,j=3, k=4,x;
    // printf("\n%u", a[0][0]);
    // printf("\n%u", &a[2][3][4]);
    // x= (i-0)*(4-0+1)*(5-0+1)+(j-0)*(5-0+1)+(k-0);
    // printf("\n%d",x);
    // printf("\n%u",a[0][0] +x);
    
    
    return 0;
}