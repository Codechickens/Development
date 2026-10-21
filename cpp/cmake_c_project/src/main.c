#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
  int data;
  struct Node *next;
};

void initNode(struct Node **first){
  *first = NULL;
};

bool emptyStack(struct Node *first){
  return first == NULL;
}

void push(struct Node **first, const int value){
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  if (!newNode) {
    printf("Cant malloc\n");
    return;
  }

  newNode->data = value;
  newNode->next = *first;
  *first = newNode;
  printf("Stack: %d\n", value);
}

int pop(struct Node **first){
  if (emptyStack(*first)){
    printf("Nothing in stack\n");
    return -1;
  }

  struct Node *temp = *first;
  int ret = temp->data;
  *first = (*first)->next;
  free(temp);
  return ret;
}

int top(struct Node *first){
  if (emptyStack(first)) {
    printf("Nothing in stack\n");
    return -1;
  }
  return first->data;
}

int main(){
  struct Node *s;
  initNode(&s);
  push(&s, 10);
  push(&s,100);
  push(&s, 9);

  pop(&s);

  printf("%d\n", top(s));

}
