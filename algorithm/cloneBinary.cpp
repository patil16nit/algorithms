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
  temp->random = NULL;
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
    cout<<"["<<node->key<<" ";
    if (node->random == NULL) {
      cout<<"NULL";
    } else {
      cout<<node->random->key;
    }
    cout<<"] ";
    inorder(node->right);
  }
}

struct node* copyLeftRight(struct node* treeNode, map<node*, node*> *myMap) {
  if (treeNode == NULL) {
     return NULL;
  }

  node* cloneNode = newNode(treeNode->key);
  (*myMap)[treeNode] = cloneNode;
  cloneNode->left = copyLeftRight(treeNode->left, myMap);
  cloneNode->right = copyLeftRight(treeNode->right, myMap);
  return cloneNode;
}

void copyRandom(node* treeNode, node* cloneNode, map<node *, node *> *mymap) {

  if (cloneNode == NULL)
    return;
  cloneNode->random =  (*mymap)[treeNode->random];
  copyRandom(treeNode->left, cloneNode->left, mymap);
  copyRandom(treeNode->right, cloneNode->right, mymap);
}
struct node *cloneTree(struct node* rootNode) {
  if (rootNode == NULL) {
    return NULL;
  }
  map<node *, node *> *newMap = new map<node *, node *>;
  node *newTree = copyLeftRight(rootNode, newMap);
  copyRandom(rootNode, newTree, newMap); 
  return newTree;
}


int main() {
  cout<<"Test"<<endl;
  node *root = NULL;
  root = insertNode(root,8);
  insertNode(root, 4);
  insertNode(root, 9);
  insertNode(root, 2);
  insertNode(root, 6);
  root->random = root->left->right;
  root->left->left->random = root;
  root->left->right->random = root->right;
  inorder(root); 
  node* clone = cloneTree(root);
  cout<<endl;
  inorder(clone);
  return 0;
}
