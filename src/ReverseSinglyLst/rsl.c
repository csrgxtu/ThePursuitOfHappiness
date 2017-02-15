#include <stdio.h>
#include <stdlib.h>

struct node {
  int data;
  struct node *next;
} *head;

void createLst(int n) {
  struct node *newNode, *temp;

  int i;
  for (i = 0; i < n; i++) {
    if (i == 0) {
      head = (struct node *)malloc(sizeof(struct node));
      if (head == NULL) {
        exit(1); // unable get free mem
      }
      temp = head;
      head->data = i;
      head->next = NULL;
    } else {
      newNode = (struct node *)malloc(sizeof(struct node));
      if (newNode == NULL) {
        exit(1); // unable get free mem
      }
      newNode->data = i;
      newNode->next = NULL;
      temp->next = newNode;
      temp = temp->next;
    }
  }
}

void reverseLst() {
  struct node *pre, *cur;
  if (head != NULL) {
    pre = head;
    cur = head->next;
    head = head->next;
    
    pre->next = NULL;
    while (head != NULL) {
      head = head->next; 
      cur->next = pre;
      pre = cur;
      cur = head;
    }
    head = pre;
  }
}

void displayLst() {
  struct node *temp;
  temp = head;

  while(temp != NULL) {
    printf("%d\n", temp->data);
    temp = temp->next;
  }
}

int main(void) {
  createLst(5);
  displayLst();
  reverseLst();
  displayLst(); 
  return 0;
}
