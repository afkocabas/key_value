#include "../include/key_value_store.h"
#include "../include/linked_list.h"
#include <stdio.h>

int main() {
  KeyValueStore *store = kv_create();
  printLinkedList(store->list);
  kv_set(store, "key1", "value1");
  printLinkedList(store->list);
  printf("The is %s\n", kv_get(store, "key2"));
  return 0;
}
