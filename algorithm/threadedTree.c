#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *left,*right;
  bool rightThread;
};

struct node* createNode(int data) {
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  temp->rightThres
} 

struct node* leftMost(struct node* node) {
  if (n==NULL) {
    return NULL;
  }
  while (n->left != NULL) {
    n = n->left;
  }
  return n;
}

void printData(struct node* node) {
  struct node* cur = leftMost(node);
  while (cur != NULL) {
    print('%d', cur->data);
    if (cur->rightThread) {
      cur = cur->right;
    } else {
      cur = leftMost(cur->right);
    }
  }  
}



int main() {
  struct node* root = (struct node*)malloc(sizeof(struct node));
  root->left
  printData(root);
  return 0;
} 

