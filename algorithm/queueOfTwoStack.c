#include<stdio.h>
#include<stdlib.h>

struct stack {
  int top;
  unsigned size;
  int * array;
};

struct stack * createStack(unsigned capacity){
  struct stack * temp = (struct stack*)malloc(sizeof(struct stack));
  temp->top = -1;
  temp->size = capacity;
  temp->array = (int*) malloc(capacity * sizeof(int)); 
  return temp;
}

int isFull(struct stack* stack) {
  return stack->top == stack->size-1;
}

int isEmpty(struct stack* stack) {
  return stack->top == -1;
}

void push(struct stack* stack, int data) {
  if (isFull(stack)) {
    return;
  }
  stack->array[++stack->top] = data;
}

int pop(struct stack* stack) {
  if (isEmpty(stack)) {
      return 0;
  }
  return stack->array[stack->top--]; 
} 

int peek(struct stack* stack) {
  if (isEmpty(stack)) {
     return 0;
  }
  return stack->array[stack->top];
}

int dequeue(struct stack* stack1, struct stack* stack2) {
  if (isEmpty(stack2)){
    while(!isEmpty(stack1)) {
      push(stack2, pop(stack1));
    }
    return pop(stack2);
  }
  return pop(stack2);
}

void enqueue(struct stack* stack1, int data) {
  if (isFull(stack1)) {
    return;
  }
  push(stack1,data);
}

void printStack(struct stack* stack) {
  if (isEmpty(stack)) {
    return;
  }

  for (int i=0; i<= stack->top;i++) { 
    printf(" %d ", stack->array[i]);
  }
}
int main() {
  struct stack* stack1 = createStack(100);
  struct stack* stack2 = createStack(100);
  enqueue(stack1,88);
  enqueue(stack1,67);
  enqueue(stack1,56);
  enqueue(stack1,3);
  printf(" dequeue => %d\n", dequeue(stack1,stack2));
  printf(" stack1 => ");
  printStack(stack1);
  printf(" \n stack2 => ");
  printStack(stack2);
  printf("\n Top item of stack1 is %d\n", peek(stack1));
  printf("Top item of stack2 is %d\n", peek(stack2));

  enqueue(stack1,45);
  printf("\n dequeue => %d\n", dequeue(stack1,stack2));
  printf(" stack1 => ");
  printStack(stack1);
  printf("\n stack2 => ");
  printStack(stack2); 
  return 0;
}
