#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int depth(struct node *temp) {
    int d=1, left=0, right=0;
    if (temp == NULL) {
        return 0;
    }
    
    if (temp->left) {
        left += d + depth(temp->left); 
    }

    if (temp->right) {
        right += d + depth(temp->right);
    }
    
    if (left  > right) {
        return left;
    } else {
        return right;
    }
}


struct node* createNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


int main(){
    // run your function through some test cases here
    // remember: debugging is half the battle!
    struct node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    printf("Depth %d", depth(root));
    return 0;
}
