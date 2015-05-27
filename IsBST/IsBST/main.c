//
//  main.c
//  IsBST
//
//  Created by allamaprabhu on 4/16/15.
//  Copyright (c) 2015 hackerRank. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


typedef struct
{
    struct node *left;
    struct node *right;
    int data;
}node;

void inOrder(node *node);
int isBST(node *n);
node *newNode(int val)
{
    node *n = (node *)malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->data = val;
    return n;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    node *n = newNode(10);
    
    node *nl = newNode(5);
    node *nr = newNode(20);
    n->left = nl;
    n->right = nr;
    
    nl->left = newNode(3);
    nl->right = newNode(7);
    
    nr->left = newNode(15);
    nr->right = newNode(25);

    if (isBST(n)) {
        printf("BST\n");
    }
    else printf("NO BST\n");
    isBST(n);
    return 0;
}

void inOrder(node *node)
{
    if (node == NULL) {
        return;
    }
    inOrder(node->left);
    printf("%d \n",node->data);
    inOrder(node->right);
}

int isBST(node *n)
{
    if (n == NULL) {
        return 1;
    }
    node *leftNode;
    leftNode = (node *)n->left;
    
    if ((leftNode != NULL) && !(leftNode->data < n->data)) {
        return 0;
    }
    if ((n->data <= leftNode->data) || !isBST(n->left)) {
        return 0;
    }
    node *rightNode = (node *)n->right;
    if (!(n->data >=rightNode->data) || !isBST(n->right)) {
        return 0;
    }
    
    return 1;
}