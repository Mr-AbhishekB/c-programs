#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}node;

node * createNode(int val){
    node * n=(node *)malloc(sizeof(node));
    n->data=val;
    n->left=NULL;
    n->right=NULL;
    return n;
}

void preOrder(node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(node * root){
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);  
    }
}

void inOrder(node * root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main(){

    //Constructing the nodes
    node * p=createNode(4);
    node * p1=createNode(1);
    node * p2=createNode(6);
    node * p3=createNode(5);
    node * p4=createNode(2);

    //Linking the root node with let and right children
    /*
    Tree looks like this:
                4
               / \
              1   6
             / \
            5   2
    */

    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);
    return 0;
}