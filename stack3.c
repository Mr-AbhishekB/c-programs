#include<stdio.h>
#include<stdlib.h>

struct stack {
    int size;
    int top;
    int *arr;
};

int isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1)
        return 1;
    else    
        return 0;
}

int isEmpty(struct stack * ptr){
    if(ptr->top==-1)
        return 1;
    else
        return 0;
}

void push(struct stack *ptr,int val){
    if(isFull(ptr))
        printf("Stack Overflow\n");
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
        return -1;
    }    
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
        
}

int peek(struct stack *ptr,int i){
    if(ptr->top-i+1<0){
        printf("Invalid Position");
        return -1;
    }
    else{
        return ptr->arr[ptr->top-i+1];
    }
}

int main(){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    int *arr=(int*)malloc(sp->size*sizeof(int));
    push(sp,10);
    push(sp,11);
    push(sp,14);
    push(sp,111);
    push(sp,22);
    push(sp,53);
    push(sp,41);
    push(sp,99);
    push(sp,76);
    push(sp,65);

    printf("%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));

    printf("Value at %d position is %d",4,peek(sp,4));
    return 0;
}