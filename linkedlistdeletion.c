#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

struct node *deleteFirstNode(struct node *head)
{
    struct node *ptr;
    ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

struct node *deleteNodeAtIndex(struct node *head, int index)
{
    int i = 0;
    struct node *p = head;
    struct node *q;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    q = p->next;
    p->next = q->next;
    return head;
}

struct node *deleteEndNode(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    return head;
}

struct node *deleteNodeGivenValue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    if (p->data == value)
    {
        head = head->next;
    }
    else
    {
        while (q->data != value && q->next != NULL)
        {
            q = q->next;
            p = p->next;
        }
        if (q->data == value)
        {
            p->next = q->next;
        }
    }
    return head;
}

int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 5;
    head->next = second;

    second->data = 7;
    second->next = third;

    third->data = 9;
    third->next = fourth;

    fourth->data = 11;
    fourth->next = NULL;

    printf("Before deletion\n");
    linkedListTraversal(head);

    // head=deleteFirstNode(head);
    // head=deleteNodeAtIndex(head,1);
    // head=deleteEndNode(head);
    head = deleteNodeGivenValue(head, 5);
    printf("After deletion\n");
    linkedListTraversal(head);
    return 0;
}