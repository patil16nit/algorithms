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

void findMinMax(node * node, int *min, int *max, int hd) {
  if (node == NULL) return;
  if (hd < *min) *min = hd;
  else if (hd > *max) *max= hd;
  findMinMax(node->left, min, max,hd-1);
  findMinMax(node->right, min, max,hd+1);  
}

void printLine(node *node, int lineNo, int hd) {
  if (node == NULL) return;
  if (lineNo == hd) {
    cout<<node->key<<" ";
  }
  printLine(node->left, lineNo, hd-1);
  printLine(node->right, lineNo, hd+1);
}


void verticalOrder(node * node) {
  int min=0, max=0;
  findMinMax(node, &min,&max, 0);
  cout<<endl<<"min ->"<<min;
  cout<<endl<<"max ->"<<max;  

  for ( int line=min; line<=max; line++) {
    cout<<endl;
    printLine(node, line, 0);
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
  inorder(root); 
  verticalOrder(root);
  return 0;
}
