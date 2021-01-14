#include <stdio.h>

#include "Graph.h"
#include "utilities.h"


#define MAX_SIZE 8
#define NUM_OF_REPETITIONS 15


int main(int argc, char *argv[])
{
    unsigned int i = 1;
    unsigned int G_size = 1;

    printf("Size\tDijkstra array\tDijkstra binheap\t        \n");
    for (; i <= MAX_SIZE; ++i) {
        if (i <= 4) {
            G_size *= 10;
            printf("10^%d", i);
        } else {
            G_size = (i-3) * 10000;
            printf("%d*10^4", (i-3));
        }
        
        create_random_graph(G_size);

        //Try Dijkstra with arrays and print results
        Graph* g1 = createGraph();
        //printGraph(g);
        double t1 = test(dijkstra_array, g1, g1->S, G_size, NUM_OF_REPETITIONS);
        //printDistancesAndPreds(g1);

        // Try Dijkstra with heaps and print results
        Graph* g2 = createGraph();
        double t2 = test(dijkstra_binheap, g2, g2->S, G_size, NUM_OF_REPETITIONS);
        //printDistancesAndPreds(g2);

        int flag = 1;
        for (int j = 0; j < G_size; ++j){
            if (g1->V[j].d != g2->V[j].d) {
                flag = 0;
                printf("One difference in d! %d vs %d\n", g1->V[j].d, g2->V[j].d);
            }
            if (g1->V[j].pred && g2->V[j].pred) {
                // I cannot compare g1->V[j].pred and g2->V[j].pred since they are different addressens since they refer to different graphs in memory (but equals in values)
                if (((Node*)g1->V[j].pred)->key != ((Node*)g2->V[j].pred)->key) {
                    flag = 0;
                    printf("One difference in pred! %d vs %d\n", ((Node*)g1->V[j].pred)->key, ((Node*)g2->V[j].pred)->key);
                }
            }
        }
    
        printf("\t%lf\t%lf", t1, t2);
        if (flag)
            printf("\t  (OK)\n");
        else
            printf("\t  (KO)\n");
    }

    return 0;
}
