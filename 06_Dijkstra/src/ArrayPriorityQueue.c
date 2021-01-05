#include <ArrayPriorityQueue.h>


ArrayPriorityQueue* build_arrayQueue(Graph* G)
{
    ArrayPriorityQueue* Q = (ArrayPriorityQueue*) malloc(sizeof(ArrayPriorityQueue));
    Q->num_of_elem = G->N;
    Q->dim_queue = G->N;
    Q->array = (Node**) malloc(G->N * sizeof(Node*));
    for(int i = 0; i < G->N; ++i) {
        Q->array[i] = &G->V[i];
    }
    return Q;
}

int is_arrayQueue_empty(const ArrayPriorityQueue *Q)
{
    return Q->num_of_elem == 0;
}

int minimum_arrayQueue(ArrayPriorityQueue *Q)
{
    unsigned long int min = Q->array[0]->d;
    for(int i = 1; i < Q->num_of_elem; ++i) {
        if(Q->array[i]->d < min) {
            min = Q->array[i]->d;
        }
    }
    return min;
}

Node* extract_min_arrrayQueue(ArrayPriorityQueue *Q)
{
    Node* node_min = (Node*) malloc(sizeof(Node));
    node_min = Q->array[0];
    for(int i = 1; i < Q->num_of_elem; ++i) {
        if(Q->array[i]->d < node_min->d) {
            node_min = Q->array[i];
        }
    }
    for(int i = node_min->key+1; i < Q->num_of_elem; ++i) {
        Q->array[i-1] = Q->array[i];
    }
    --Q->num_of_elem;

    return node_min;
}

const Node* decrease_key_arrrayQueue(ArrayPriorityQueue* Q, Node* node, const int value)
{
    Q->array[node->key]->d = value;
    return Q->array[node->key];
}

void insert_value_arrrayQueue(ArrayPriorityQueue* Q, Node* n)
{
    if(Q->dim_queue > Q->num_of_elem)
        Q->array[Q->num_of_elem] = n;
    else {
        Node** a = (Node**) malloc(2 * Q->dim_queue * sizeof(Node*));
        for(int i = 0; i < Q->num_of_elem; ++i) {
            a[i] = Q->array[i];
        }
        a[Q->num_of_elem] = n;
        free(Q->array);
        Q->array = a;
    }
    ++Q->num_of_elem;
    return;
}

void printQueue(const ArrayPriorityQueue* Q, void (*key_printer)(const void *value))
{
  for(int i = 0; i < Q->num_of_elem; ++i) {
        key_printer(Q->array[i]);
    }
  printf("\n");

  return;
}