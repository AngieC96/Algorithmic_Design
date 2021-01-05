#ifndef __DIJKSTRA__
#define __DIJKSTRA__

/**
 * @file
 *
 * It will contain the Dijkstra Algorithm.
 * 
 * Single Source Shortest Paths: 
 * We want to compute all the shortest paths from a single node s.
 */

#include <stdlib.h>
#include <limits.h>

#include "List.h"
#include "Graph.h"


void init_sssp(Graph* G);

void relax(Q, v, u, w);

void dijkstra(Graph* G, int s);

#endif // __DIJKSTRA__