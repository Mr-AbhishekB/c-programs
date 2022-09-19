#include<stdio.h>
#include<stdlib.h> 

typedef struct node{
    int data;
    struct node * next;
}node;

void traversal(node * top){
    node * n=top;
    while(n!=NULL){
        printf("%d ",n->data);
        n=n->next;
    }
    printf("\n");
}

int isEmpty(node * top){
    if(top==NULL)
        return 1;
    else 
        return 0;
}

int isFull(node * top){
    node *n=(node *)malloc(sizeof(node));
    if(n==NULL)
        return 1;
    else{
        free(n);
        return 0;
    }
}

node * push(node * top,int val){
    if(isFull(top))
        printf("Stack Overflow\n");
    else{
        node *n=(node *)malloc(sizeof(node));
        n->data=val;
        n->next=top;
        top=n;
        return top;
    }
}

int pop(node **top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        node * n=*top;
        *top=(*top)->next;
        int i=n->data;
        return i;
    }
}

int main(){
    node *top=NULL;

    top=push(top,5);
    top=push(top,4);
    top=push(top,1);
    top=push(top,4);
    top=push(top,7);
    

    traversal(top);

    printf("%d\n",pop(&top));

    return 0;
}