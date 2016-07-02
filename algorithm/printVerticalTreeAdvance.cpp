#include<iostream>
#include<map>
#include<string>
#include<vector>
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


void getVerticalOrder(node* node, int hd, map<int, vector<int> > &m) {
  if (node==NULL) return;
  m[hd].push_back(node->key);
  getVerticalOrder(node->left, hd-1, m);
  getVerticalOrder(node->right, hd+1,m);
}

void printVertical(node * node ) {
  map<int, vector<int> > m;
  int hd=0;
  getVerticalOrder(node, hd, m);

  map<int, vector<int> >:: iterator it;
  for (it= m.begin(); it != m.end(); it++) {
     for (int i=0; i < it->second.size(); ++i)
       cout << it->second[i] << " ";
     cout << endl;
  }
}


void inorder(struct node *node) {
  if (node != NULL) {
    inorder(node->left);
    cout<<node->key<<" "; 
    inorder(node->right);
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
  cout<<endl<<"Inorder -> ";
  inorder(root); 
  cout<<endl<<"Vertical ->"<<endl;
  printVertical(root);
  
  return 0;
}
