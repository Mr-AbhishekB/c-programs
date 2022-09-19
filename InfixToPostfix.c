#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stack
{
    int top;
    int size;
    char *arr;
} stack;

int isFull(stack *ptr)
{
    if (ptr->top == ptr->size - 1)
        return 1;
    else
        return 0;
}

int isEmpty(stack *ptr)
{
    if (ptr->top == -1)
        return 1;
    else
        return 0;
}

void push(stack *ptr, char val)
{
    if (isFull(ptr))
        printf("Stack Overflow\n");
    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return -1;
    }
    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char stackTop(stack *sp)
{
    return sp->arr[sp->top];
}

int isOperator(char a)
{
    if (a == '+' || a == '-' || a == '/' || a == '*')
        return 1;
    else
        return 0;
}

int precedence(char a)
{
    if (a == '+' || a == '-')
        return 1;
    else if (a == '*' || a == '/')
        return 2;
}

char *inToPo(char *infix)
{
    stack *sp = (stack *)malloc(sizeof(stack));
    sp->top = -1;
    sp->size = 100;
    sp->arr = (char *)malloc(sp->size * sizeof(char));

    char *postfix = (char *)malloc(strlen((infix) + 1) * sizeof(char));
    int i = 0; // tracking prefix
    int j = 0; // filling postfix
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++, j++;
        }
        else
        {
            if(sp->top==-1){
                push(sp,infix[i]);
                i++;
            }
            if (precedence(infix[i]) > precedence(stackTop(sp)))
            {
                push(sp, infix[i]);
                i++;
            }
            else if(precedence(stackTop(sp))>=precedence(infix[i]))
            {
                postfix[j] = pop(sp);
                j++;
            }   
        }
    }
    while (!isEmpty(sp))
    {
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main()
{
    char infix[] = "x-y/z-k*d";
    printf("Postfix is %s", inToPo(infix));
    return 0;
}