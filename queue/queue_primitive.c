#include<stdio.h>
#include<stdlib.h>
#define queuesize 10
#define TRUE 1
#define FALSE 0
struct Queue {
    int item[queuesize];
    int front;
    int rear;
};

struct Queue q;

void initialize(struct Queue *q){
    q->front =0;
    q->rear=-1;
}
void enque(struct Queue *q,char x){
    if (q->rear==queuesize-1){
        printf("queue Overflow");
        exit(1);
    }
    else{
        q->rear=q->rear+1;
        q->item[q->rear]=x;
    }

}
int IsEmpty(struct Queue *q){
    if (q->rear- q->front +1==0){
        return TRUE;
    }
    else{
        return FALSE;
    }
}
char deque(struct Queue *q){
    if(IsEmpty(q)){
        printf("queue Underflow");
        exit(1);
    }
    else{
        char x=q->item[q->front];
        q->front=q->front+1;
        return x;
    }
}

int main(){
    char y;
    struct Queue myq;
    initialize(&myq);

    while(TRUE){
        char choice;
        printf("enter 1 to insert\n");
        printf("enter 2 to delete\n");
        printf("enter 3 to exit\n");
        scanf("%c", choice);

        switch(choice){
            case 1: 
                printf("enter element to to entered\n");
                scanf("%c", &y);
                enque(&myq, 'y');
            case 2:
                
                deque(&myq);
                printf("element deleted is %c\n", y);
                break;
            case 3:
                exit(1);
        }

    }

    // enque(&myq, 'a');
    // enque(&myq, 'b');
    // enque(&myq, 'c');
    
    // char y= deque(&myq);
    // printf("deleted elem is %c ", y);
     
    return 0;
}