#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void linkedListTraversal(struct node *top){
    while(top!=NULL){
        printf("%d ",top->data);
        top=top->next;
    }
    printf("\n");
}

int isEmpty(struct node * top){
    if(top==NULL)
        return 1;
    else    
        return 0;
}

int isFull(struct node * top){
    struct node * n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL)
        return 1;
    else{
        free(n);
        return 0;
    }
}

struct node * push(struct node * top,int val){
    if(isFull(top))
        printf("Stack Overflow\n");
    else{
        struct node * n=(struct node *)malloc(sizeof(struct node));
        n->data=val;
        n->next=top;
        top=n;
        return top;
    }
}

int pop(struct node ** top){
    if(isEmpty(*top)){
        printf("Stack Underflow\n");
    }
    else{
        struct node * n=*top;
        *top=(*top)->next;
        int i=n->data;
        free(n);
        return i;
        
    }
}

int peek(struct node * top,int pos){
    struct node * ptr=top;
    for(int i=0;(i<pos-1 && ptr!=NULL);i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL)
        return ptr->data;
    else    
        printf("Invalid\n");
}

int main(){
    struct node*top=NULL;
    printf("%d\n",isEmpty(top));
    top=push(top,8);
    top=push(top,9);
    top=push(top,88);
    top=push(top,66);
    printf("%d\n",isEmpty(top));
    int element=pop(&top);
    printf("Element popped- %d\n",element);
    linkedListTraversal(top);
    int i=peek(top,2);
    printf("%d",i);
    return 0;
}