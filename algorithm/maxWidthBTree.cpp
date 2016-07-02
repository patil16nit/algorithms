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

int height(struct node* node) {
  if (node == NULL) {
    return 0;
  }
  int lheight = height(node->left);
  int rheight = height(node->right);
  return (lheight>rheight)?(lheight+1):(rheight+1);
}

int getWidth(node* treeNode, int level) {
  if (treeNode == NULL) {
    return 0;
  }
  if(level == 1) {
    return 1;
  }
  return getWidth(treeNode->left, level-1) + getWidth(treeNode->right, level-1);
}


int getMaxWidth(node* node, int h) {
  int maxWidth = 0;
  int width;  
  for(int i =1;i<=h;i++) {
    width = getWidth(node,i);
    if(width > maxWidth){
      maxWidth = width;
    }
    cout<<endl<<i<<" level ->"<<width<<endl;
  }
  return width;
}


int main() {
  cout<<"Test"<<endl;
  node *root = NULL;
  root = insertNode(root,8);
  insertNode(root, 4);
  insertNode(root, 9);
  insertNode(root, 2);
  insertNode(root, 6);
  inorder(root);
  cout<<endl<<"Maximum width -> "<<getMaxWidth(root,height(root))<<endl;
  return 0;
}
