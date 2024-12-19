#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Actual KW pair stored in the linked list
typedef struct {
  char *key;
  char *value;
} KVPair;

// Linked list node
typedef struct Node {
  KVPair *data;
  struct Node *next;
} Node;

// DS to store KWPairs
typedef struct {
  Node *head;
  Node *tail;
} LinkedList;

// FUNCTION DECLARATIONS
LinkedList *createLinkedList();
void freeLinkedList(LinkedList *list);
void printLinkedList(LinkedList *list);

Node *createNode(const char *key, const char *value);
void deleteNode(LinkedList *list, const char *key);
void freeNodeData(Node *node);
const char *get(LinkedList *list, const char *key);
void set(LinkedList *list, const char *key, const char *value);
Node *ifExist(LinkedList *list, const char *key);

#endif
