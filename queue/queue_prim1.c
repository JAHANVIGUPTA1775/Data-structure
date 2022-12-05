#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define queuesize 10

struct queue{
    int rear;
    int front;
    int item[queuesize];
};

void initialize(struct queue *q){
    q->rear=-1;
    q->front =0;
}

int isempty(struct queue *q){
    if((q->rear-q->front +1)==0){
        return 1;
    }
    else{
        return 0;
    }
}

void enque(struct queue *q,int x){
    if(q->rear==queuesize-1){
        printf("queue overflow");
        exit(1);
    }

    q->rear++;
    q->item[q->rear]=x;
}
int deque(struct queue *q){
    if(isempty(q)){
        printf("queue underflow");
        exit(1);
    }

    int x=q->item[q->front];
    q->front++;
    return x;
}

int main(){
    struct queue q;
    initialize(&q);
    enque(&q,40);
    enque(&q,10);
    enque(&q,20);
    enque(&q,30);
    int x=deque(&q);
    printf("%d",x);

}