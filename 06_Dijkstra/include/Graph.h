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
    ListNode* adjacencyList;
} Graph;

Graph createGraph();

#endif // __GRAPH__