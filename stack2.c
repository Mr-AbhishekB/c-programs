#include<stdio.h>
#include<stdlib.h>

struct stack{
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


int main(){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=10;
    sp->top=-1;
    sp->arr=(int *)malloc(sp->size*sizeof(int));
    printf("%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));

    push(sp,5);

    printf("%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));

    printf("Popped value- %d\n",pop(sp));

    printf("%d\n",isFull(sp));
    printf("%d\n",isEmpty(sp));
    
    return 0;
}