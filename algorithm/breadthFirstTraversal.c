#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* left, *right;
};


struct node * newNode (int d ){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = d;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}


int height(struct node* node) {
  if (node == NULL) {
    return 0;
  }
  int lheight = height(node->left);
  int rheight = height(node->right);

  if (lheight>=rheight) {
    return lheight+1;
  } else {
    return rheight+1;
  }
} 

void printIndividualLevel(struct node* node, int d) {
  if (node == NULL) {
    return;
  }
  if (d == 1) {
    printf("  %d ", node->data);
  } else if(d>1) {
    printIndividualLevel(node->left, d-1);
    printIndividualLevel(node->right, d-1);
  }
}


void printLevels(struct node * node) {
 int he = height(node);
 for(int h=1;h<=he;h++) {
   printIndividualLevel(node,h);
 }
}


int main () {

  struct node * node = newNode(9);
  node->left = newNode(6);
  node->right = newNode(10);
  node->left->left = newNode(3);
  node->left->right = newNode(7);
  node->right->left = newNode(8);
  node->right->right = newNode(14);
  printf("\n height of the tree %d \n",height(node));
  printLevels(node);
  return 0;
}
