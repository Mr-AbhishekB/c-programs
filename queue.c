#include<stdio.h>
#include<stdlib.h>

typedef struct queue{
    int f;
    int b;
    int size;
    int *arr;
}queue;

int isFull(queue*q){
    if(q->b==q->size-1)
        return 1;
    else    
        return 0;
}

int isEmpty(queue*q){
    if(q->f==q->b)
        return 1;
    else
        return 0;
}

void enqueue(queue *q,int val){
    if(isFull(q)){
        printf("Queue Overflow\n");
    }
    else    
        q->b++;
        q->arr[q->b]=val;
}

int dequeue(queue *q){
    int a=-1;
    if(isEmpty(q))
        printf("Queue Underflow, returning -1\n");
    else{
        q->f++;
        a=q->arr[q->f];
    }
    return a;
}

int main(){ 
    queue *q=(queue *)malloc(sizeof(queue));
    q->f=0;
    q->b=0;
    q->size=100;
    q->arr=(int *)malloc(q->size*sizeof(int));

    enqueue(q,12);
    enqueue(q,15);

    if(isEmpty(q))
        printf("Queue is empty\n");

    if(isFull(q))
        printf("Queue is full\n");

    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));

    if(isEmpty(q))
        printf("Queue is empty\n");

    return 0;
}