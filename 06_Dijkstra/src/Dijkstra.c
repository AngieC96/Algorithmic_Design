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
    while (!is_arrayQueue_empty(Q)) {   // One node u is extracted at each iteration, the one with minimum d
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
    //PRINTF("\tQ.A before heapify: ");
    //for(int i = 0; i < Q->num_of_elem; ++i)
    //    PRINTF("[%d, %d] ", ((Node*)Q->A)[i].key, ((Node*)Q->A)[i].d);
    //PRINTF("\n");
    heapify(Q, 0);
    //PRINTF("\tQ.A after heapify: ");
    //for(int i = 0; i < Q->num_of_elem; ++i)
    //    PRINTF("[%d, %d] ", ((Node*)Q->A)[i].key, ((Node*)Q->A)[i].d);
    //PRINTF("\n");
    if(u->d + w < v->d){
        // Update distance in the queue Q
        // I need to manually modify the value of d in the node of the queue, since with decrease_key I cannot d it (it doesn't access the field d)
        int i;
        for(i = 0; i < Q->num_of_elem; ++i) {
            if (((Node*)Q->A)[i].key == v->key)
                ((Node*)Q->A)[i].d = u->d + w;
        }
        // Update distance in the graph's set of nodes V
        decrease_dist(v, u->d + w);
        v->pred = u;
    }
    //PRINTF("\tQ.A after modification: ");
    //for(int i = 0; i < Q->num_of_elem; ++i)
    //    PRINTF("[%d, %d] ", ((Node*)Q->A)[i].key, ((Node*)Q->A)[i].d);
    //PRINTF("\n");
    heapify(Q, 0);
    //PRINTF("\tQ.A after heapify2: ");
    //for(int i = 0; i < Q->num_of_elem; ++i)
    //    PRINTF("[%d, %d] ", ((Node*)Q->A)[i].key, ((Node*)Q->A)[i].d);
    //PRINTF("\n");
}

void dijkstra_binheap(Graph* G, int s)
{
    init_sssp(G);
    G->V[s].d = 0;
    // I need an array for the queue since it is an inplace algorithm, and if I use G.V thenit swaps the
    // nodes there and that's no good, since in G.V[0] has to be node 0, in G.V[1] has to be node 1, etc.
    Node* A = (Node*) malloc(G->N * sizeof(Node));
    for (int i = 0; i < G->N; ++i)
        memcpy(&A[i], &G->V[i], sizeof(Node));
    binheap_type* Q = build_heap(A, G->N, G->N, sizeof(Node), leq_d); // All the nodes are in Q at the beginning of the computation
    //PRINTF("\tQ.A after heapify: ");
    //for(int i = 0; i < Q->num_of_elem; ++i)
    //    PRINTF("[%d, %d] ", ((Node*)Q->A)[i].key, ((Node*)Q->A)[i].d);
    //PRINTF("\n");
    while (!is_heap_empty(Q)) {   // One node u is extracted at each iteration, the one with minimum d
        Node* u = extract_min(Q);
        //PRINTF("Node %d\n", u->key);
        ListNode* tmp = G->adjacencyList[u->key];
        while(tmp) {   // iterates on the adjacency list of u
            relax_heap(Q, &G->V[u->key], &G->V[((Pair*)tmp->T)->a], ((Pair*)tmp->T)->b);
            //PRINTF("\tInside while. Node %d, weigth %d (tmp)\n", ((Pair*)tmp->T)->a, ((Pair*)tmp->T)->b);
            tmp = tmp->next;
        }
    }
    delete_heap(Q);
}