#include <Graph.h>


Graph* createAdjacencyList()
{
    FILE *fp = fopen("data/input.txt", "r");
    if(fp == NULL) {
      printf("Error reading file!\n");
      exit(1);
    }
    int N, M, S, a, b;
    // Otherwise, to delete N and M from the file: count the number of different numbers and then do while(fscanf)
    fscanf(fp, "%d %d %d", &N, &M, &S);
    Graph g;
    g.adjacencyList = (ListNode*) malloc(N * sizeof(ListNode**)); // array of size N listing the nodes
    /*
    for(int i = 0; i < N; ++i) {
        g.adjacencyList[i] = NULL;
    }
    for(int i = 0; i < M; ++i) {
      fscanf(fp, "%d %d", &a, &b);
      push_back_void(g.adjacencyList[a], &b);
    }
    printf("Printing list:\n");
    printList(g.adjacencyList[0], int_t);

*/
    fclose(fp);
}

//void printGraph()
