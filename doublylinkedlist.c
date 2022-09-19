#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
    struct node *previous;
};

void traversalFromStart(struct node *n1){
    struct node *p=n1;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

void traversalFromEnd(struct node *last){
    struct node *p=last;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->previous;
    }
    printf("\n");
}

int main(){
    struct node * n1=(struct node *)malloc(sizeof(struct node));   
    struct node * n2=(struct node *)malloc(sizeof(struct node));   
    struct node * n3=(struct node *)malloc(sizeof(struct node));   
    struct node * n4=(struct node *)malloc(sizeof(struct node));   
    
    n1->data=15;
    n1->previous=NULL;
    n1->next=n2;

    n2->data=18;
    n2->next=n3;
    n2->previous=n1;

    n3->data=19;
    n3->previous=n2;
    n3->next=n4;

    n4->data=22;
    n4->previous=n3;
    n4->next=NULL;

    traversalFromStart(n1);

    insert

    traversalFromEnd(n4);
    return 0;
}