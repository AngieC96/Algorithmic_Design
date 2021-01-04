#include <Node.h>

void printNode(const Node* n, void (*key_printer)(const void *value))
{
  printf("[%d, ", n->key);
  key_printer(n->value);
  printf("] ");

  return;
}



