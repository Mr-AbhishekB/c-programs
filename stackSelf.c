#include<stdio.h>
#include<malloc.h>

typedef struct stack{
    int top;
    int size;
    int *arr;
}stack; 

int isEmpty(stack * s){
    if(s->top==-1)
        return 1;
    else    
        return 0;
}

int isFull(stack *s){
    if(s->top==s->size-1)
        return 1;
    else 
        return 0;
}

void push(stack *s,int val){
    if(isFull(s)){
        printf("Stack Overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=val;
    }    
}

int pop(stack *s){
    if(isEmpty(s)){
        printf("Stack Underflow\n"); 
        return -1;
    }
    else{    
        int pop=s->arr[s->top];
        s->top--;
        return pop;
    }    
}

int stackTop(stack * s){
    return s->arr[s->top];
}

int stackBottom(stack * s){
    return s->arr[0];
}

int peek(stack * s, int pos){
    if(s->top-pos+1<0 || s->top-pos+1>s->size){
        printf("Invalid Position\n");
    }
    else
        return s->arr[s->top-pos+1];
}

int main(){
    stack *s=(stack *)malloc(sizeof(stack));
    s->size=5;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));

    push(s,5);
    push(s,8);
    push(s,1);
    push(s,2);
    push(s,9);

    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));
    printf("%d\n",pop(s));

    return 0;

}