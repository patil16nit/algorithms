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

void lca(node* node,int first, int second) {
  if (node==NULL) {
    return;
  }
  if (node->key>=first && node->key<second) {
    cout<<"lca -> "<<node->key;
    return;
  }
  lca(node->left,first,second);
  lca(node->right, first,second);
}


int main() {
  cout<<"Test"<<endl;
  node *root = NULL;
  root = insertNode(root,20);
  insertNode(root, 8);
  insertNode(root, 22);
  insertNode(root, 4);
  insertNode(root, 12);
  insertNode(root, 10);
  insertNode(root, 14);
  inorder(root); 
  cout<<endl;
  lca(root, 10, 14);
  return 0;
}
