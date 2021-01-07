#include <Dijkstra.h>

#define INFTY 999999999

void init_sssp(Graph* G)
{
    for (int i = 0; i < G->N; ++i){
        G->V[i].d = INT_MAX;  // = INFTY;
        G->V[i].pred = NULL;
    }
}

//void relax(Q, v, u, w)
//{
    // if(u.d + w < v.d){
    //     decrease_key(Q, v, u.d + w);
    // }
//}

void dijkstra_array(Graph* G, int s)
{
    init_sssp(G);
    G->V[s].d = 0;
    printf("Ciao\n");
    //ArrayPriorityQueue* Q = build_arrayQueue(G);
    // All the nodes are in Q at the beginning of the computation
    //while (!is_arrayQueue_empty(Q))  // One node u is extracted at each iteration
    //{
        //printf("In Dijkstra\n");
        //Node* u = extract_min_arrrayQueue(Q);
        //while(G->adjacencyList[u->key] && G->adjacencyList[u->key]->next)  // iterates on the adjacency list of u
        //printf("Inside while\n");
        //printf("%d, %d\n", ((Pair*)G->adjacencyList[u->key]->T)->a, ((Pair*)G->adjacencyList[u->key]->T)->b);
        //for (v, w) in G.Adj(u){
        //    relax(Q, u, v, w);
        //}
    //}
}

void dijkstra_binheap(Graph* G, int s)
{    
    //init_sssp(G);
    //G->V[s].d = 0;
    
    // binheap_type* Q = build_heap(???);
    // Q <- G.V;  // All the nodes are in Q at the beginning of the computation
    // while (!is_queue_empty(Q))  // One node u is extracted at each iteration
    // {
    //     u = extract_min(Q);
    //     for (v, w) in G.Adj(u){  // iterates on the adjacency list of u
    //         relax(Q, u, v, w);
    //     }
    // }
}