#include <Graph.h>


void createAdjacencyList(Graph* g)
{
    FILE *fp = fopen("data/input.txt", "r");
    if(fp == NULL) {
      printf("Error reading file!\n");
      exit(1);
    }

    int a, b;
    // Otherwise, to delete N and M from the file: count the number of different numbers and then do while(fscanf)
    fscanf(fp, "%d %d %d", &g->N, &g->M, &g->S);

    g->adjacencyList = (ListNode**) malloc(g->N * sizeof(ListNode*)); // array of size N listing the nodes
    for(int i = 0; i < g->N; ++i) {
        g->adjacencyList[i] = NULL;
    }
    for(int i = 0; i < g->M; ++i) {
      fscanf(fp, "%d %d", &a, &b);
      Node* n = (Node*) malloc(sizeof(Node));
      n->key = b;
      push_back_void(&g->adjacencyList[a], n);
    }

    fclose(fp);
}

void printGraph(Graph* g)
{
  printf("Graph adjacency list:\n");
    for(int i = 0; i < g->N; ++i) {
      printf("Node [%d]: ", i);
      printList(g->adjacencyList[i], printNode);//(int_printer));
///home/angela/Documenti/Algorithmic Design/Algorithmic_Design/06_Dijkstra/src/Graph.c:35:38: warning: passing argument 2 of ‘printList’ from incompatible pointer type [-Wincompatible-pointer-types]
//       printList(g->adjacencyList[i], printNode);//(int_printer));
//                                      ^~~~~~~~~
//In file included from /home/angela/Documenti/Algorithmic Design/Algorithmic_Design/06_Dijkstra/include/Graph.h:15:0,
//                 from /home/angela/Documenti/Algorithmic Design/Algorithmic_Design/06_Dijkstra/src/Graph.c:1:
///home/angela/Documenti/Algorithmic Design/Algorithmic_Design/06_Dijkstra/include/List.h:62:6: note: expected ‘void (*)(const void *)’ but argument is of type ‘void (*)(const Node *, void (*)(const void *)) {aka void (*)(const struct <anonymous> *, void (*)(const void *))}’
// void printList(const ListNode* l, void (*key_printer)(const void *value));
//      ^~~~~~~~~
    }
}
