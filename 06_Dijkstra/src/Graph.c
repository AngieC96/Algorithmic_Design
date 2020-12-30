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
      push_back_void(&g->adjacencyList[a], &b);
    }

    fclose(fp);
}

//void printGraph()
