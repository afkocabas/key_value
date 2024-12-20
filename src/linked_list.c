#include "../include/linked_list.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

LinkedList *createLinkedList() {
  LinkedList *linked_list = (LinkedList *)malloc(sizeof(LinkedList));
  linked_list->head = NULL;
  linked_list->tail = NULL;
  return linked_list;
}

void freeLinkedList(LinkedList *list) {
  Node *current = list->head;
  while (current != NULL) {
    Node *temp = current;
    freeNodeData(temp);
    current = current->next;
    free(temp);
  }
  list->head = NULL;
  list->tail = NULL;
  free(list);
}

void freeNodeData(Node *node) {
  free(node->data->key);
  free(node->data->value);
  free(node->data);
}

Node *createNode(const char *key, const char *value) {
  KVPair *kvPair = (KVPair *)malloc(sizeof(KVPair));
  if (!kvPair) {
    fprintf(stderr, "createNode: Memory allocation for KWPair failed.\n");
    return NULL;
  }
  kvPair->key = strdup(key);
  kvPair->value = strdup(value);
  if (!kvPair->key || !kvPair->value) {
    fprintf(stderr, "createNode: strdup for key or value failed.\n");
    free(kvPair->key);
    free(kvPair->value);
    free(kvPair);
    return NULL;
  }

  // Allocate memory for the node
  Node *node = (Node *)malloc(sizeof(Node));
  if (!node) {
    fprintf(stderr, "createNode: Memory allocation for Node failed.\n");
    free(kvPair->key);
    free(kvPair->value);
    free(kvPair);
    return NULL;
  }

  node->data = kvPair;
  node->next = NULL;
  return node;
}

void deleteNode(LinkedList *list, const char *key) {
  if (list->head == NULL) {
    printf("No element in list.\n");
    return;
  }

  Node *current = list->head;
  if (strcmp(current->data->key, key) == 0) {
    list->head = current->next;
    if (list->head == NULL) {
      list->tail = NULL; // List is now empty
    }
    freeNodeData(current);
    free(current);
    return;
  }

  while (current->next != NULL) {
    if (strcmp(current->next->data->key, key) == 0) {
      Node *nodeToDelete = current->next;
      current->next = current->next->next;
      // In case the last element - tail element - is deleted
      if (nodeToDelete == list->tail) {
        list->tail = current;
      }
      freeNodeData(nodeToDelete);
      free(nodeToDelete);
    }
    current = current->next;
  }
  printf("No such key\n");
}
Node *ifExist(LinkedList *list, const char *key) {
  if (list->head == NULL) {
    return NULL;
  }

  Node *current = list->head;
  while (current != NULL) {
    if (strcmp(current->data->key, key) == 0)
      return current;
    current = current->next;
  }
  return NULL;
}

const char *get(LinkedList *list, const char *key) {
  Node *node = ifExist(list, key);
  if (node != NULL)
    return node->data->value;
  else
    return NULL;
}

void set(LinkedList *list, const char *key, const char *value) {
  Node *node = ifExist(list, key);
  // In case the key already exists.
  if (node != NULL) {
    free(node->data->value);
    node->data->value = strdup(value);
    if (!node->data->value) {
      fprintf(stderr, "set: Memory allocation failed for node->data->value.\n");
    }
    return;
  }

  Node *newNode = createNode(key, value);
  if (newNode == NULL) {
    fprintf(stderr, "set: Memory allocation failed for new node.\n");
    return;
  }

  if (list->head == NULL) {
    list->head = newNode;
    list->tail = newNode;
    return;
  }

  list->tail->next = newNode;
  list->tail = newNode;
}
void printLinkedList(LinkedList *list) {
  if (list->head == NULL) {
    printf("[]\n");
    return;
  }

  Node *current = list->head;
  while (current != NULL) {
    printf("(%s | %s) ->", current->data->key, current->data->value);
    current = current->next;
  }
  printf(" NULL\n");
}
