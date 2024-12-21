#ifndef COMMAND_H
#define COMMAND_H
#include "./key_value_store.h"
#define MAX_INPUT 256
void handle_command(KeyValueStore *store, char *input);
#endif
