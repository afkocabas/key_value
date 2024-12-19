#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>

// Actual KW pair stored in the linked list
typedef struct {
  char *key;
  char *value;
} KWPair;

// Linked list node
typedef struct Node {
  KWPair *data;
  struct Node *node;
} Node;

// DS to store KWPairs
typedef struct {
  Node *head;
  Node *tail;
} LinkedList;

// FUNCTION DECLARATIONS
LinkedList *createLinkedList();
void freeLinkedList(LinkedList *list);

Node *createNode(const char *key, const char value);
void deleteNode(LinkedList list, const char *key);
void printLinkedList(LinkedList *list);
const char *get(LinkedList list, const char *key);
void *set(LinkedList list, const char *key, const char *newValue);
bool ifExist(char *key);

#endif
