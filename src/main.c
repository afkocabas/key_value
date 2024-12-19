#include "../include/linked_list.h"
#include <stdio.h>

int main() {
  LinkedList *list = createLinkedList();
  printLinkedList(list);
  set(list, "ahmet", "mehmet");
  set(list, "ali", "kemal");
  printLinkedList(list);
  deleteNode(list, "ahmet");
  deleteNode(list, "ali");
  printLinkedList(list);
  if (ifExist(list, "ahmet") == NULL) {
    printf("The key value does not exists in the base\n");
  } else {
    printf("key found!\n");
  }
  return 0;
}
