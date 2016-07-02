#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* left, *right;
};

struct node *newNode(int data) {
  struct node* temp = (struct node*)malloc(sizeof(struct node)); 
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
};

struct node* insertNode(struct node* node, int data) {
 
  if (node == NULL){
    return newNode(data);
  }

  if (data <= node->data) {
    node->left = insertNode(node->left, data);
  } else {
    node->right = insertNode(node->right, data);
  }
  return node;
}

void print(struct node* node) {
  if (node==NULL) {
    return;
  }
  print(node->left);
  printf("%d\n", node->data);
  print(node->right);
}


void secondLargestCompute(struct node* node, int *c) {
  if (node == NULL || (*c)>2) {
    return;
  }
  
  secondLargestCompute(node->right, &(*c));
  (*c)++;
  if (*c==2) {
      printf("Second Larget element in BST is => %d", node->data);
      return;  
  }
  secondLargestCompute(node->left, &(*c));
}

void secondLarget(struct node * node) { 
  int c = 0;
  secondLargestCompute(node,&c);
}



int main() {
  /*
            60
           /  \
          10  80
             /  \
            75  90

  */
  struct node *root = newNode(60); 
  //root = insertNode(root,60);
  struct node *left = insertNode(root, 10);
  struct node *right = insertNode(root, 80);
  struct node *rightL = insertNode(right, 75);
  //root = insertNode(root, 90);
  print(root);
  
  secondLarget(root);
  printf("%d",3/2);
  return 0;
}
