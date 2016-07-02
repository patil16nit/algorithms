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

void pushToMaxStack(struct stack* maxStack, int data) {
  if (isFull(maxStack)) {
    return;
  }
  maxStack->array[++maxStack->top] = data;
}

void push(struct stack* stack, struct stack* maxStack,int data) {
  if (isFull(stack)) {
    return;
  }
  if (data>= peek(maxStack)) {
     pushToMaxStack(maxStack,data);
  }
  stack->array[++stack->top] = data;
}


int popMaxStack(struct stack * maxStack) {
  if (isEmpty(maxStack)) {
      return 0;
  }
  return maxStack->array[maxStack->top--];  
}

int pop(struct stack* stack, struct stack* maxStack) {
  if (isEmpty(stack)) {
      return 0;
  }
  if (peek(maxStack) == peek(stack)) {
     popMaxStack(maxStack); 
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
  struct stack* maxStack = createStack(50); 
  push(stack,maxStack,10);
  push(stack,maxStack,89);
  push(stack,maxStack,79);
  push(stack,maxStack,50);
  push(stack,maxStack,2);
  push(stack,maxStack,100);
  printf("%d popped from stack\n", pop(stack,maxStack));
  printf("Top item is %d\n", peek(stack));
  printf("Largest element in the stack -> %d \n", peek(maxStack)); 
  return 0;
}
