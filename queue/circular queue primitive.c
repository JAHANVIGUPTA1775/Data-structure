#include<stdio.h>
#include<stdlib.h>
#define queuesize 10
#define TRUE 1
#define FALSE 0
struct cQueue {
    int item[queuesize];
    int front;
    int rear;
};

struct cQueue q;

void initialize(struct cQueue *cq){
    cq->front =queuesize-1;
    cq->rear=queuesize-1;
}
void enque(struct cQueue *cq,char x){
    if ((cq->rear+1)%queuesize== cq->front){
        printf("queue Overflow");
        exit(1);
    }
    else{
        cq->rear=(cq->rear+1)%queuesize;
        cq->item[cq->rear]=x;
    }

}
int IsEmpty(struct cQueue *cq){
    if (cq->rear== cq->front){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
char deque(struct cQueue *cq){
    if(IsEmpty(cq)){
        printf("queue Underflow");
        exit(1);
    }
    else{
        cq->front= (cq->front+1)% queuesize;
        char x=cq->item[cq->front];
        
        return x;
    }
}

int main(){
    struct cQueue myq;
    initialize(&myq);
    enque(&myq, 'a');
    enque(&myq, 'b');
    enque(&myq, 'c');
    enque(&myq, 'd');

    char y= deque(&myq);
    printf("deleted elem is %c", y);
    return 0;
}