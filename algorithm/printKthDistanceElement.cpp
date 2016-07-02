#include<iostream>
#include<map>
#include<string>

using namespace std;

struct node {
  int key;
  struct node *right, *left, *random;
};

struct node * newNode(int key) {
  struct node *temp = (struct node*)malloc(sizeof(struct node));
  temp->key = key;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

struct node* insertNode(struct node *node, int data) {
  if (node == NULL) {
    return newNode(data);
  }
  if (data <= node->key) {
    node->left = insertNode(node->left,data);
  } else {
    node->right = insertNode(node->right, data);
  }
  return node;
}


void inorder(struct node *node) {
  if (node != NULL) {
    inorder(node->left);
    cout<<node->key<<" "; 
    inorder(node->right);
  }
}

void printKthElements(node* node, int k) {
  if (node == NULL)  {
    return;
  }
  if (k==1) {
    cout<<node->key<<" ";
    return;
  } else {
    printKthElements(node->left, k-1);
    printKthElements(node->right, k-1);
  }
  
}


int main() {
  cout<<"Test"<<endl;
  node *root = NULL;
  root = insertNode(root,8);
  insertNode(root, 4);
  insertNode(root, 9);
  insertNode(root, 2);
  insertNode(root, 6);
  insertNode(root, 7);
  insertNode(root, 10);
  inorder(root); 
  cout<<endl;
  printKthElements(root,3);
  return 0;
}
