#include <Node.h>


const Node* decrease_dist(Node* node, const int value)
{
    node->d = value;
    return node;
}

void printNode(const Node* n, void (*key_printer)(const void *value))
{
  printf("[key: %d, ", n->key);
  //key_printer(n->value);
  printf("satellite data: , ");  // FIND A WAY TO PRINT IT!!!!
  printf("d: %d, ", n->d);
  printf("pred: %p]", n->pred);

  return;
}



