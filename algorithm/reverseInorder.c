#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node* left;
  struct node* right;
};

struct node* createNode(int x) {
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL; 
  return temp;
};



struct node* addNode(struct node* node,int d) {
  if (node == NULL) {
    return createNode(d);
  }

  if (node->data > d) {
      node->left=addNode(node->left, d);
  } else {
      node->right=addNode(node->right, d);
  }
  return node;
}

void inorder(struct node* root) {
   if (root == NULL) {
      return;
   }
   inorder(root->left);
   printf("%d ", root->data);
   inorder(root->right);

}


int main() {

   struct node* root = createNode(10);
   root = addNode(root, 5);
   root = addNode(root, 15);
   root = addNode(root, 20);

   inorder(root);

   return 0;
}  
