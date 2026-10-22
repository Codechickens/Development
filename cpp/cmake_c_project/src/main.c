#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct sNode{
  int data;
  struct sNode* next;
};

struct sNode* initNode(int value){
  struct sNode *newNode = (struct sNode*)malloc(sizeof(struct sNode));
  if (newNode == NULL){
    printf("Heap overflow");
    exit(1);
  }

  newNode->data = value;
  newNode->next = NULL;
  return newNode;
}

bool emptyNode(struct sNode* head){
  return head == NULL;
}
void insertHead(struct sNode** head, int value){
  struct sNode* newNode = initNode(value);
  newNode->next =  *head;
  *head = newNode;
}

void insertEnd(struct sNode** head, int value){
  if (emptyNode(*head)){
    *head = initNode(value);
    return;
  }

  struct sNode* newNode = initNode(value);
  struct sNode* curr = *head;

  while(curr->next!=NULL){
    curr = curr->next;
  }
  curr->next=newNode;
}

void getVal(struct sNode* head){
  if(emptyNode(head)){
    printf("NULL\n");
    return;
  }
  while (head != NULL) {
    printf("[%d] -> ", head->data);
    head = head->next;
  }
  printf("NULL\n");
}
int main(){
  struct sNode *n = NULL;

  insertHead(&n, 99);
  insertEnd(&n, 100);

  getVal(n);

}
