#include <stdio.h>
#include <time.h>
#include <string.h>

#include "Graph.h"
#include "Dijkstra.h"

void int_printer(const void *value);

void float_printer(const void *value);

double test(void (*dikstra)(Graph* G, int s), 
            Graph* G, int s, const unsigned int n, 
            const unsigned int rep);

void create_random_graph(const unsigned int n);
