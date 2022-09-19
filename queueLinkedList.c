#include<stdio.h>
#include<stdlib.h>


typedef struct node{
    int data;
    struct node * next;
}node;

node *f=NULL;
node *r=NULL;
void linkedListTraversal(node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

void enqueue(int val){
    node *n=(node*)malloc(sizeof(node));
    if(n==NULL)
        printf("Queue is full\n");
    else{
        n->data=val;
        n->next=NULL;
        if(f==NULL)
            f=r=n;
        else{
            r->next=n;
            r=n;
        }
    }
        
}

int dequeue(){
    int val=-1;
    node *ptr=f;
    if(f==NULL){
        printf("Queue is empty\n");
    }
    else{
        f=f->next;
        val=ptr->data;
        free(ptr);
    }
    return val;
}

int main(){

    printf("%d\n",dequeue());
    enqueue(5);
    enqueue(2);
    enqueue(7);
    enqueue(9);

    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());
    printf("%d\n",dequeue());

    linkedListTraversal(f);

    return 0;
}