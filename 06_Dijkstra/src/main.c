#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "List.h"
#include "Node.h"
#include "Graph.h"
#include "ArrayPriorityQueue.h"
#include "Dijkstra.h"
#include "utilities.h"

#define int_t(i) *((const int *)i)
#define float_t(f) *((const float *)f)


int main(int argc, char *argv[])
{
    /* printf("Lista:\n");
    ListNode* list = NULL;
    printf("Void list: %p\n", list);
    // Create and print an int linked list
    int arr[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i)
       list = push_back(list, &arr[i]);
       //push_back(list, &arr[i]);
    printf("Value in head: %d\n", int_t(list->T));
    printf("Value in head+1: %d\n", int_t(list->next->T));
    int x = 60, y=70;
    push_back(list, &x);
    push_back(list, &y);
    printList(list, int_printer);
    
    // Create and print a float linked list 
    ListNode* list2 = NULL;
    float arr2[] = {10.1, 20.2, 30.3, 40.3, 50.5};
    for (int i = 0; i < 5; ++i)
        push_back_void(&list2, &arr2[i]);
    printf("Value in head: %.2f\n", float_t(list2->T));
    printf("Value in head+1: %.2f\n", float_t(list2->next->T));
    printList(list2, float_printer);

    Ldestructor(&list);
    Ldestructor(&list2);
    printf("Destroyed list: %p\n", list); */

    //printf("Grafo:\n");
    //Graph g;
    //g.adjacencyList = NULL;
    //int a = 10, b=20;
    // push_back_void(&g.adjacencyList, &a);
    // push_back_void(&g.adjacencyList, &b);
    // printf("Value in head: %d\n", int_t(g.adjacencyList->T));
    // printf("Value in head+1: %d\n", int_t(g.adjacencyList->next->T));
    // printList(g.adjacencyList, int_printer);
/*
    ListNode** adjacencyList = (ListNode**) malloc(10 * sizeof(ListNode*));
    adjacencyList[0] = NULL;
    printList(adjacencyList[0], int_printer);
    push_back_void(&adjacencyList[0], &a);
    printList(adjacencyList[0], int_printer);
*/
    //createAdjacencyList(&g);
/*  Graph* g = createGraph();
    printf("Nodes: %d,\tEdges: %d,\tSource: %d\n", g->N, g->M, g->S);
    printGraph(g);
    printf("Content of node %d: %p\n", g->V[3].key, g->V[3].value);

    ArrayPriorityQueue* q = build_arrayQueue(g);
    printf("Queue # elem: %d\n", q->num_of_elem);
    printf("Queue content: ");
    printQueue(q, printNode);
    int mamma = INT_MAX;
    printf("\nMAX: %d\n", mamma);
    init_sssp(g);
    printf("Content of node.d %d: %d\n", g->V[0].key, g->V[0].d);
    printf("Min of queue: %d\n", minimum_arrayQueue(q));
    printf("Graph distances: ");
    for(int i = 0; i < g->N; ++i) {
        g->V[i].d = i;
        printf("%d ", g->V[i].d);
    }
    printf("\n");
    decrease_key_arrrayQueue(q, &g->V[4], 2);
    printf("Queue content: ");
    printQueue(q, printNode);
    printf("Min of queue: %d\n", extract_min_arrrayQueue(q)->key);
    printf("Queue # elem: %d\n", q->num_of_elem);
    printf("Queue content: ");
    printQueue(q, printNode);
    insert_value_arrrayQueue(q, &(g->V[0]));
    printf("Queue content: ");
    printQueue(q, printNode);
    insert_value_arrrayQueue(q, &(g->V[2]));
    printf("Queue content: ");
    printQueue(q, printNode);

    init_sssp(g);
    printf("Graph distances: ");
    for(int i = 0; i < g->N; ++i) {
        printf("%d ", g->V[i].d);
    }
    printf("\n");
    printf("La coda è vuota? %d\n", is_arrayQueue_empty(q));
*/

    printf("Dijkstra:\n");
    Graph* gg = createGraph();
    printGraph(gg);
    dijkstra_array(gg, gg->S);
    printf("Distance of source: %d\n", gg->V[gg->S].d);


    return 0;
}
