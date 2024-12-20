#include "../include/key_value_store.h"
#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

KeyValueStore *kv_create() {
  LinkedList *list = createLinkedList();
  if (!list) {
    fprintf(stderr, "kv_create: Failed to create LinkedList.\n");
    return NULL;
  }
  KeyValueStore *store = (KeyValueStore *)malloc(sizeof(KeyValueStore));
  if (!store) {
    fprintf(stderr, "kv_create: Failed to create KeyValueStore.\n");
    free(list);
    return NULL;
  }
  store->list = list;
  return store;
}

void kv_set(KeyValueStore *store, const char *key, const char *value) {
  set(store->list, key, value);
}

const char *kv_get(KeyValueStore *store, const char *key) {
  const char *result = get(store->list, key);
  return result;
}

void kv_delete(KeyValueStore *store, const char *key) {
  deleteNode(store->list, key);
}

bool kv_exists(KeyValueStore *store, const char *key) {
  return ifExist(store->list, key) != NULL;
}

void kv_free(KeyValueStore *store) {
  if (!store)
    return;
  freeLinkedList(store->list);
  free(store);
}
