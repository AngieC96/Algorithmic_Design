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

#include "ArrayPriorityQueue.h"
#include "Graph.h"

#include "binheap.h"  //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#ifdef NO_OUTPUT
#define PRINTF(...)
#else
#define PRINTF(...) printf(__VA_ARGS__)
#endif


void init_sssp(Graph* G);

void relax_array(ArrayPriorityQueue* Q, Node* u, Node* v, int w);

void dijkstra_array(Graph* G, int s);

void relax_heap(binheap_type* Q, Node* u, Node* v, int w);

void dijkstra_binheap(Graph* G, int s);

#endif // __DIJKSTRA__