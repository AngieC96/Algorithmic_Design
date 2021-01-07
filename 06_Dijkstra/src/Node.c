#include <Node.h>


const Node* decrease_dist(Node* node, const int value)
{
    printf("In decrease, node: %d\n", node->key);
    node->d = value;
    printf("In decrease_key: %d\n", Q->array[node->key]->key);
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



