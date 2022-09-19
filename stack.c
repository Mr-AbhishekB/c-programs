//Stack is a liner data structure
#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack ptr){
    printf("jsfnjdnb");
    if(ptr.top==-1){
        printf("is empty\n");
        return 1;
    }    
    else
        return 0;
}

int isFull(struct stack ptr){
    if(ptr.top==ptr.size-1)
        return 1;
    else    
        return 0;
}

int main(){
    struct stack s;
    s.size=80;
    s.top=-1;
    s.arr=(int *)malloc(s.size * sizeof(int));
    printf("Inside main\n");
    // struct stack *s;
    // s->size=80;
    // s->top=-1;
    // s->arr=(int *)malloc(s->size * sizeof(int));
    printf("Before isEmpty");
    int i=isEmpty(s);
    if(i==-1){
        printf("stack is empty\n");
    
    }    
    else
        printf("stack is not empty");

    return 0;

}