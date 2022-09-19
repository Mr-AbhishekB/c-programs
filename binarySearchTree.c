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

void inOrder(node * root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int isBST(node * root){
    if(root!=NULL){
        
    }
    else    
        return NULL;
}

int main(){

    //Constructing the nodes
    node * p=createNode(5);
    node * p1=createNode(3);
    node * p2=createNode(6);
    node * p3=createNode(1);
    node * p4=createNode(4
    );

    //Linking the root node with let and right children
    /*
    Tree looks like this:
                5
               / \
              3   6
             / \
            1   4
    */
    p->left=p1;
    p->right=p2;
    p1->left=p3;
    p1->right=p4;

    inOrder(p);
    printf("\n");

    return 0;
}