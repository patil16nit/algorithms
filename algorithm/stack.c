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

int main() {
  struct stack* stack = createStack(100);
  push(stack,10);
  push(stack,30);
  push(stack,40);
  push(stack,50);
  push(stack,50); 
  printf("%d popped from stack\n", pop(stack));
  printf("Top item is %d\n", peek(stack)); 
  return 0;
}
