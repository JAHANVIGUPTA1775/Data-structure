#include <stdio.h>
struct student{
    int roll;
    int sec;
    float percent;
    int mob;
};

int main()
{
    //struct student s={98211, 'B', 84.25, 3447};
    // scanf("%d", &s.roll);
    // scanf("%c", &s.sec);
    // scanf("%f", &s.percent);
    // scanf("%d", &s.mob);
    struct student s[5];
    int i;
    for(i=0; i<5; i++){
        scanf("%d", &s[i].roll);
        scanf("%d", &s[i].sec);
        scanf("%f", &s[i].percent);
        scanf("%d", &s[i].mob);
    }
    
    // printf("%d\t", s.roll);
    // printf("%c\t", s.sec);
    // printf("%f\t", s.percent);
    // printf("%d\t", s.mob);
    
    for(i=0; i<5; i++){
        printf("%d\t", s[i].roll);
        printf("%d\t", s[i].sec);
        printf("%f\t", s[i].percent);
        printf("%d\n", s[i].mob);
    }

    return 0;
}
