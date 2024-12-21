#include "../include/command.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

void handle_command(KeyValueStore *store, char *input) {
  char command[MAX_INPUT], key[MAX_INPUT], value[MAX_INPUT],
      unnecessary[MAX_INPUT];
  int returnValue =
      sscanf(input, "%s %s %s %s", command, key, value, unnecessary);
  // If there is no input word
  if (returnValue < 1) {
    return;
  }
  if (returnValue > 3) {
    printf("Invalid use of commands. See :help\n");
  }
  // If there is command
  if (returnValue == 1) {
    if (strcasecmp(command, "exit") == 0) {
      printf("Exiting..\n");
      exit(0);
    } else if (strcasecmp(command, "print") == 0) {
      printLinkedList(store->list);
    } else if (strcasecmp(command, "set") == 0) {
      printf("The SET commands should be used in form of <keyword> "
             "<key> <value>\n");
    } else if (strcasecmp(command, "exists") == 0) {
      printf("The EXISTS commands should be used in form of <keyword> "
             "<key>\n");
    } else if (strcasecmp(command, "get") == 0) {
      printf("The GET commands should be used in form of <keyword> "
             "<key>\n");
    } else {
      printf("Unknown command.\n");
    }
  } else if (returnValue == 2) {
    if (strcasecmp(command, "get") == 0) {
      const char *result = kv_get(store, key);
      if (result) {
        printf("Value for key '%s': %s\n", key, result);
      } else {
        printf("Key '%s' not found.\n", key);
      }
    } else if (strcasecmp(command, "delete") == 0) {
      kv_delete(store, key);
    }
  } else if (returnValue == 3) {
    if (strcasecmp(command, "set") == 0) {
      kv_set(store, key, value);
    }
  }
}
