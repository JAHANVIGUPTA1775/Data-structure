#include <stdio.h>
struct student{
    int roll;
    int phy;
    int maths;
    int chem;
};

int main()
{
    int n;
    scanf("%d", &n);
    struct student s[n];
    int i;
    for(i=0; i<n; i++){
        scanf("%d", &s[i].roll);
        scanf("%d", &s[i].phy);
        scanf("%d", &s[i].maths);
        scanf("%d", &s[i].chem);
    }
    
    
    
    for(i=0; i<n; i++){
        // printf("%d\t", s[i].roll);
        // printf("%d\t", s[i].phy);
        // printf("%f\t", s[i].maths);
        // printf("%d\n", s[i].chem);
        float p= ((s[i].phy+ s[i]. maths+ s[i]. chem)/300.0)*100;
        printf("percent of roll no %d = %f%%", s[i].roll, p);
    }
    

    return 0;
}

