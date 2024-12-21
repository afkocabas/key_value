#include "../include/command.h"
#include "../include/key_value_store.h"
#include <stdio.h>
#include <strings.h>

int main() {
  char input[MAX_INPUT];
  KeyValueStore *store = kv_create();
  while (1) {
    printf("> ");
    if (!fgets(input, sizeof(input), stdin)) {
      return 1;
    }
    handle_command(store, input);
  }
  return 0;
}
