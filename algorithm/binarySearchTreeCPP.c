#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    int count;
    struct node *left, *right;
};

struct node *newNode(int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key   = data;
    temp->count = 1;
    temp->left  = NULL;
    temp->right = NULL;
    return temp;
};

void in_order(struct node *node) {
    if(node == NULL) {
        return;
    }
    in_order(node->left);
    printf("%d (%D)",node->key, node->count);
    in_order(node->right);
}

struct  node *insert(struct node *node , int key) {
    if (node == NULL) return newNode(key);
    if (key == node->key) {
        node->count++;
        return node;
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    } else {
        node->right =insert(node->right, key);
    }
    return node;
}

int main() {
    struct node *root = NULL;
    root = insert(root,12);
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 9);
    root = insert(root, 11);
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 12);

    in_order(root);

    return 0;
}
