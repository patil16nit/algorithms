#include<iostream>
#include<map>
#include<string>
#define MAX_INT 100
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

struct stack {
  int size;
  int top;
  struct node *array;
};

struct node* createStack(int size) {
  struct stack *stack = (struct stack*)malloc(sizeof(struct stack));
  stack->size = size;
  stack->top = -1;
  stack->array = (struct node**)malloc(stack->size * sizeof(struct node*));
  return stack;
}

int  isFull(struct stack* stack) {
  return (stack->top - 1)== (stack->size);
}

int isEmpty(struct stack* stack) {
  return stack->top == -1; 
}

void push(struct stack *stack, struct node *node) {
  if (isFull(stack)) {
     return;
  }
  stack->array[++stack->top]=node;
}

struct node* pop(struct stack* stack) {
  if(isEmpty(stack)) return NULL;
  return stack->array[stack->top--];
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

bool isPairPresent(struct node* root, int target) {
  struct stack* s1 = createStack(MAX_INT);
  struct stack* s2 = createStack(MAX_INT); 
  bool done1 = false, done2 = false;
  int val1 = 0, val2 = 0;
  struct node *curr1 = root, *curr2 = root;
  while(1) {
    while (done1==false) {
      if (curr1 != NULL)
            {
                push(s1, curr1);
                curr1 = curr1->left;
            }
            else
            {
                if (isEmpty(s1))
                    done1 = 1;
                else
                {
                    curr1 = pop(s1);
                    val1 = curr1->val;
                    curr1 = curr1->right;
                    done1 = 1;
                }
            }
    }
             while (done2 == false)
        {
            if (curr2 != NULL)
            {
                push(s2, curr2);
                curr2 = curr2->right;
            }
            else
            {
                if (isEmpty(s2))
                    done2 = 1;
                else
                {
                    curr2 = pop(s2);
                    val2 = curr2->val;
                    curr2 = curr2->left;
                    done2 = 1;
                }
            }
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
  inorder(root); 
  return 0;
}
