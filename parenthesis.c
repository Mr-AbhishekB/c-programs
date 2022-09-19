#include<stdio.h>
#include<stdlib.h>

struct stack{
    int top;
    int size;
    char *arr;

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

char pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
        return -1;
    }    
    else{
        int val=ptr->arr[ptr->top];
        ptr->top--;
    }
        
}

int parenthesisMatch(char *exp){
    struct stack *sp=(struct stack *)malloc(sizeof(struct stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size * sizeof(char));
    for(int i=0;i<exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(sp,'(');
        }
        else if(exp[i]==')'){
            if(isEmpty(sp))
                return 0;
            else    
                pop(sp);
        }
    }
    if(isEmpty(sp))
        return 1;
    else    
        return 0;
}

int main(){
    char exp[]="(6-7+7-8)-(2-3)";
    if(parenthesisMatch(exp))
        printf("Parenthesis is matching");
    else    
        printf("Parenthesis is not matching");


    return 0;
}