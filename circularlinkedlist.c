#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node * next;
};

void traversal(struct node *head){
    struct node *p=head;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=head);
    printf("\n");
}

struct node *insertAtFirst(struct node *head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head->next;
    ptr->data=data;
    while(p->next!=head){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=head;
    head=ptr;
    return head;

}

struct node * insertBetweenNodes(struct node * head,int index,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    struct node *q=head->next;
    int i=0;
    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }
    ptr->data=data;
    p->next=ptr;
    ptr->next=q;
    return head;
}

struct node * inserAtEnd(struct node * head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *q=head->next;
    while(q->next!=head){
        q=q->next;
    }
    ptr->data=data;
    q->next=ptr;
    ptr->next=head;
    return head;
}

struct node * insertAfterNode(struct node *head,struct node*preNode,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=preNode->next->next;
    preNode->next=ptr;
    return head;
}


int main(){
    struct node * head=(struct node *)malloc(sizeof(struct node));   
    struct node * first=(struct node *)malloc(sizeof(struct node));   
    struct node * second=(struct node *)malloc(sizeof(struct node));   
    struct node * third=(struct node *)malloc(sizeof(struct node));   

    head->data=5;
    head->next=first;

    first->data=9;
    first->next=second;

    second->data=11;
    second->next=third;

    third->data=15;
    third->next=head;

    printf("Before insertion\n");
    traversal(head);

    // head=insertAtFirst(head,99);
    // head=insertBetweenNodes(head,1,100);
    // head=inserAtEnd(head,20);
    head=insertAfterNode(head,first,115);
    printf("After insertion\n");
    traversal(head);
    
    return 0;
}