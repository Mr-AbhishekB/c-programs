#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node * createNode(int val){
    node * n=(node *)malloc(sizeof(node));
    n->data=val
    n->left=NULL;
    n->right=NULL;
    return n;
}

int main(){
    // //Constructing the root node
    // node * p=(node *)malloc(sizeof(node));
    // p->data=5
    // p->left=NULL;
    // p->right=NULL;

    // //Constructing the second node
    // node * p1=(node *)malloc(sizeof(node));
    // p1->data=1
    // p1->left=NULL;
    // p1->right=NULL;

    // //Constructing the third node
    // node * p2=(node *)malloc(sizeof(node));
    // p2->data=2
    // p2->left=NULL;
    // p2->right=NULL;

    // //Linking the root node with left and right children
    // p->left=p1;
    // p->right=p2;

    node *p=createNode(2);
    node *p1=createNode(4);
    node *p2=createNode(1);
    //Linking the root node with left and right children
    p->left=p1;
    p->right=p2;
    return 0;
}