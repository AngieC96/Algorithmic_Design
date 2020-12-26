#ifndef __GRAPH__
#define __GRAPH__

/**
 * @file
 *
 * It will contain the Graph-related code
 */

#include <stdlib.h>
#include <limits.h>  // for ULONG_MAX

#include "List.h"
#include "PriorityQueue.h"
#include "Node.h"


/** @struct Graph
 *  @brief A class to represent a graph.
 *
 *  This class is meant to represent a graph.
 */
typedef struct {
    List adjacencyl;
} Graph;

#endif // __GRAPH__