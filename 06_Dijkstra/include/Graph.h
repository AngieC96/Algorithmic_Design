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
    ListNode** adjacencyList;
} Graph;

void createAdjacencyList(Graph* g);

Graph createGraph();

#endif // __GRAPH__