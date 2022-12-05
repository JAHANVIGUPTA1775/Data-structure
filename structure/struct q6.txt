#include <stdio.h>
struct times{
    int hrs;
    int min;
    int sec;
};
int main()
{
    struct times t1= {7,31,54};
    struct times t2={2,55,36};
    struct times t;
    t.sec=(t1.sec + t2.sec)%60;
    int s= (t1.sec + t2.sec)/60;
    
    t.min=(t1.min + t2.min +s)%60;
    int m= (t1.min + t2.min+s)/60;
    
    t.hrs=(t1.hrs + t2.hrs+m);
    //int hr= (t1.hrs + t2.hrs+ m)/60;
    printf("%d %d %d", t.hrs, t.min, t.sec);

    return 0;
}
