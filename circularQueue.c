#include<stdio.h>
#include<stdlib.h>

typedef struct circularQueue{
    int f;
    int b;
    int size;
    int *arr;
}circularQueue;

int isEmpty(circularQueue*q){
    if(q->f==q->b)
        return 1;
    else
    return 0;
}

int isFull(circularQueue*q){
    if((q->b+1)%q->size==q->f)
        return 1;
    else
        return 0;
}

void enqueue(circularQueue*q,int val){
    if((q->b+1)%q->size==q->f)
        printf("Queue Overflow\n");
    else{
        q->b=(q->b+1)%q->size;
        q->arr[q->b]=val;
        printf("%d has been enqueued\n",val);
    }
}

int dequeue(circularQueue*q){
    int val=-1;
    if(isEmpty(q))
        printf("Empty queue\n");
    else{
        q->f=(q->f+1)%q->size;
        val=q->arr[q->f];
    }
    return val;
}

int main(){ 
    circularQueue *q=(circularQueue *)malloc(sizeof(circularQueue));
    q->f=0;
    q->b=0;
    q->size=4;
    q->arr=(int *)malloc(q->size*sizeof(int));

    enqueue(q,3);
    enqueue(q,5);
    enqueue(q,6);
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    return 0;
}