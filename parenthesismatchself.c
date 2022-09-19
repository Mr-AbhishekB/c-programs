#include<stdio.h>
#include<stdlib.h>

typedef struct stack{
    int size;
    int top;
    char *arr;
}stack;

int isFull(stack *ptr){
    if(ptr->top==ptr->size-1)
        return 1;
    else    
        return 0;
}

int isEmpty(stack * ptr){
    if(ptr->top==-1)
        return 1;
    else
        return 0;
}

void push(stack *ptr,char val){
    if(isFull(ptr))
        printf("Stack Overflow\n");
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}

char pop(stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack Underflow\n");
        return -1;
    }    
    else{
        char val=ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
        
}

int match(char a, char b){
    if(a=='(' && b==')')
        return 1;
    if(a=='{' && b=='}')
        return 1;
    if(a=='[' && b==']')
        return 1;
}

int parenthesisMatch(char *exp){
    stack *sp=(stack *)malloc(sizeof(stack));
    sp->size=100;
    sp->top=-1;
    sp->arr=(char *)malloc(sp->size*sizeof(char));
    char popped;

    for(int i=0;exp[i]!='\0';i++){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(sp,exp[i]);
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty(sp))
                return 0;
            else{
                popped=pop(sp);
                if(!match(popped,exp[i]))
                    return 0;
            }
        }
    }
    if (isEmpty(sp))
        return 1;
    else   
         return 0;
}

int main(){
    char exp[]="[{2-3-(6-7)}-{4-6+((8-7)-3)}]";
    if(parenthesisMatch(exp))
        printf("Parenthesis is balanced\n");
    else
        printf("Parenthesis is not balanced\n");
    return 0;
}