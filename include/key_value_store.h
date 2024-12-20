#ifndef KEY_VALUE_STORE_H
#define KEY_VALUE_STORE_H
#include "linked_list.h"
#include <stdbool.h>

typedef struct {
  LinkedList *list;
} KeyValueStore;

KeyValueStore *kv_create();
void kv_set(KeyValueStore *store, const char *key, const char *value);
const char *kv_get(KeyValueStore *store, const char *key);
void kv_delete(KeyValueStore *store, const char *key);
bool kv_exists(KeyValueStore *store, const char *key);
void kv_free(KeyValueStore *store);

#endif
