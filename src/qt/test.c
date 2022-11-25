#include <stdio.h>

#include "s21_calc.h"

typedef struct node {
  int data;
  struct node* next;
} nodes;

nodes* makeList() {
  nodes* headNode = NULL;
  nodes* secondNode = NULL;
  nodes* thirdNode = NULL;

  headNode = malloc(sizeof(nodes));
  secondNode = malloc(sizeof(nodes));
  thirdNode = malloc(sizeof(nodes));

  headNode->data = 1;
  headNode->next = secondNode;

  secondNode->data = 2;
  secondNode->next = thirdNode;

  thirdNode->data = 3;
  thirdNode->next = NULL;

  return headNode;
}

void printList(nodes* headNode) {
  nodes* currentNode = headNode;
  while (currentNode != NULL) {
    printf("The current element is %d\n", currentNode->data);
    currentNode = currentNode->next;
  }
}

void reverse_func(nodes* headNode, int data) {
  nodes* tmp = calloc(1, sizeof(nodes));
  tmp->data = headNode->data;
  tmp->next = headNode;
  headNode = tmp;
}

nodes* copy_func(nodes* headNode) {
  nodes* currentNode;
  nodes* tmp;
  while (headNode != NULL) {
    currentNode = headNode;
    reverse_func(headNode, headNode->data);
    headNode = headNode->next;
    free(currentNode);
  }
  return tmp;
}

int main() {
  nodes* res = NULL;
  nodes* ls = makeList();
  printList(ls);
  res = copy_func(ls);
  return 0;
}