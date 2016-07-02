#include<stdio.h>
#include<stdlib.h>
#define MAX_Q_SIZE 500

struct node {
  int data;
  struct node* left, *right;
};



struct node** createQueue(int *front, int *rear ) {
  struct node** queue = (struct node**) malloc(sizeof(struct node*)*MAX_Q_SIZE);
  *front= *rear = 0;
  return queue;
}

void enQueue(struct node** queue, int * rear, struct node* node) {
  queue[*rear] = node;
  (*rear)++;
}

struct node* deQueue(struct node** queue, int * front) {
  (*front)++;
  return queue[*front - 1];
}

struct node * newNode (int d ){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = d;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}


void printLevelOrder(struct node* root) {
  int rear,front;
  struct node** queue = createQueue(&front, &rear);
  struct node* temp = root;
  while(temp) {
    printf(" %d ", temp->data);
    if (temp->left)
      enQueue(queue, &rear, temp->left);
    if (temp->right)
      enQueue(queue, &rear, temp->right);
    temp = deQueue(queue, &front);
  }
}

int main () {
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5);
  printLevelOrder(root); 
  return 0;
}
