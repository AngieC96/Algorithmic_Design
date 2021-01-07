#include <Dijkstra.h>

#define INFTY 999999999

void init_sssp(Graph* G)
{
    for (int i = 0; i < G->N; ++i){
        G->V[i].d = INT_MAX;  // = INFTY;
        G->V[i].pred = NULL;
    }
}

void relax(ArrayPriorityQueue*Q, Node* u, Node* v, int w)
{
    if(u->d + w < v->d){
        decrease_dist(v, u->d + w);
        v->pred = u;
    }
}

void dijkstra_array(Graph* G, int s)
{
    init_sssp(G);
    G->V[s].d = 0;
    ArrayPriorityQueue* Q = build_arrayQueue(G);    // All the nodes are in Q at the beginning of the computation
    while (!is_arrayQueue_empty(Q)) {   // One node u is extracted at each iteration
        Node* u = extract_min_arrrayQueue(Q);
        ListNode* tmp = G->adjacencyList[u->key];
        while(tmp) { // iterates on the adjacency list of u
            relax(Q, &G->V[u->key], &G->V[(int)((Pair*)tmp->T)->a], (int)((Pair*)tmp->T)->b);
            tmp = tmp->next;
        }
    }
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