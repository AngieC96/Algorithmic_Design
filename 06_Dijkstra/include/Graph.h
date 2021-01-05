#ifndef __GRAPH__
#define __GRAPH__

/**
 * @file
 *
 * It will contain the Graph-related code.
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <limits.h>  // for ULONG_MAX

#include "List.h"
#include "Node.h"
#include "utilities.h"


/** @struct Graph
 *  @brief A class to represent a graph.
 *
 *  This class is meant to represent a graph.
 */
typedef struct {
    /** @brief First number. */
    int a;
    /** @brief Second number. */
    int b;
} Pair;

void printPair(Pair * p);

/** @struct Graph
 *  @brief A class to represent a graph.
 *
 *  This class is meant to represent a graph.
 */
typedef struct {
    /** @brief The number of nodes. */
    int N;
    /** @brief The number of edges. */
    int M;
    /** @brief The source of the graph. */
    int S;
    /** @brief The adjacency list of the graph. */
    ListNode** adjacencyList;
    /** @brief The set (vector) of edges of the graph. */
    Node* V;
} Graph;

Graph* createGraph();

void createAdjacencyList(Graph* g);

void printGraph(Graph* g);

#endif // __GRAPH__