#include <Dijkstra.h>

#define INFTY 999999999

void init_sssp(Graph* G)
{
    for (int i = 0; i < G->N; ++i){
        G->V[i].d = INT_MAX;  // = INFTY;
        G->V[i].pred = NULL;
    }
}

void relax(ArrayPriorityQueue* Q, Node* u, Node* v, int w)
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
    ArrayPriorityQueue* Q = build_arrayQueue(G);   // All the nodes are in Q at the beginning of the computation
    while (!is_arrayQueue_empty(Q)) {   // One node u is extracted at each iteration
        Node* u = extract_min_arrrayQueue(Q);
        ListNode* tmp = G->adjacencyList[u->key];
        while(tmp) {   // iterates on the adjacency list of u
            relax(Q, &G->V[u->key], &G->V[(int)((Pair*)tmp->T)->a], (int)((Pair*)tmp->T)->b);
            tmp = tmp->next;
        }
    }
}

void relax_heap(binheap_type* Q, Node* u, Node* v, int w)
{
    if(u->d + w < v->d){
        //decrease_dist(v, u->d + w);
        decrease_key(Q, v, u->d + w);
        v->pred = u;
    }
}

void dijkstra_binheap(Graph* G, int s)
{    
    init_sssp(G);
    G->V[s].d = 0;
    binheap_type* Q = build_heap(G->V, G->N, G->N, sizeof(Node), leq_d); // All the nodes are in Q at the beginning of the computation
    printf("Addresses: %p = %p\n", G->V, Q->A);
    printf("G.V: ");
    for(int i = 0; i < G->N; ++i)
        printf("[%d, %d] ", G->V[i].key, G->V[i].d);
    printf("\n");
    printf("Q.A: ");
    //for(int i = 0; i < G->N; ++i){
    //    Node aaa = ((Node) Q->A)[i];
    //    printf("[%d, %d] ", aaa.key, aaa.d);}
    //printf("\n");
    print_heap(Q, printNode);
    while (!is_heap_empty(Q)) {   // One node u is extracted at each iteration
        Node* u = extract_min(Q);
        printf("Node %d, in graph: %p\n", u->key, &G->V[u->key]);
        ListNode* tmp = G->adjacencyList[u->key];
        while(tmp) {   // iterates on the adjacency list of u
            relax_heap(Q, &G->V[u->key], &G->V[(int)((Pair*)tmp->T)->a], (int)((Pair*)tmp->T)->b);
            heapify(Q, 0);
            printf("\tInside while. Node %d, weigth %d\n", (int)((Pair*)tmp->T)->a, (int)((Pair*)tmp->T)->b);
            print_heap(Q, printNode);
            tmp = tmp->next;
        }
    }
}