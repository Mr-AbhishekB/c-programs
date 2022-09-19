#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node*next;
};

void linkedListTraversal(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}

struct node * insertAtFirst(struct node *head,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->data=data;
    ptr->next=head;
    return ptr;
}

struct node * insertAtIndex(struct node * head,int data,int index){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    struct node *p=head;
    int i=0;
    while(i!=(index-1)){
        p=p->next;
        i++;
    }
    ptr->next=p->next;
    ptr->data=data;
    p->next=ptr;
    return head;

}

struct node * insertAtEnd(struct node *head,int data){
    struct node *p=head;
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    ptr->data=data;
    return head;
}

struct node * insertAfterNode(struct node *head,struct node *prevNode,int data){
    struct node *ptr=(struct node *)malloc(sizeof(struct node));
    ptr->next=prevNode->next;
    prevNode->next=ptr;
    ptr->data=data;
    return head;
}


int main(){
    struct node *head=(struct node *)malloc(sizeof(struct node));
    struct node *second=(struct node *)malloc(sizeof(struct node));
    struct node *third=(struct node *)malloc(sizeof(struct node));
    head->data=5;
    head->next=second;
    second->data=8;
    second->next=third;
    third->data=12;
    third->next=NULL;
    
    linkedListTraversal(head);

    head=insertAtFirst(head,65);
    linkedListTraversal(head);

    head=insertAtIndex(head,6,4);
    linkedListTraversal(head);

    head=insertAtEnd(head,99);
    linkedListTraversal(head);

    head=insertAfterNode(head,second,100);
    linkedListTraversal(head);

    return 0;
}