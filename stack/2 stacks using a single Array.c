#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define n 100
#define TRUE 1
#define FALSE 0
#define m 2
int item[n];
int TOP1, TOP2;

/*****************/
void initialise1(){
    TOP1=-1;
}
void initialise2(){
    TOP2=100;
}
/**********************/
int isEmpty1()
{
    if(TOP1==-1)
        return TRUE;
    else
        return FALSE;
}
int isEmpty2()
{
    if(TOP1==100)
        return TRUE;
    else
        return FALSE;
}
/********************************/
void push1(int x){
    if(TOP1==TOP2-1 && TOP1==99){
        printf("stack overflow");
        exit(1);
    }
    TOP1++;
    item[TOP1]=x;
}
void push2(int x){
    if(TOP2==0 && TOP2==TOP1+1){
        printf("stack overflow");
        exit(1);
    }
    TOP2--;
    item[TOP2]=x;
}
/********************************/
int pop1(){
    if (isEmpty1()){
        printf("stack underflow");
        exit(1);
    }
    int x=item[TOP1];
    TOP1--;
    return x;
}
int pop2(){
    if (isEmpty2()){
        printf("stack underflow");
        exit(1);
    }
    int x=item[TOP2];
    TOP2++;
    return x;
}
/*********************/

int stacktop1(){
    int x=item[TOP1];
    return x;
} 
int stacktop2(){
    int x=item[TOP2];
    return x;
} 

/********************************/

int main(){
    initialise1();
    initialise2();
    push1(1);
    push2(2);
    printf("%d",stacktop1());
}
