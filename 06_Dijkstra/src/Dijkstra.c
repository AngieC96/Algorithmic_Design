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
        decrease_dist(v, u->d + w);
        decrease_key(Q, v, u->d + w);
        v->pred = u;
    }
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
    printf("Addresses: %p = %p are equal %d\n", G->V, Q->A, G->V == Q->A);
    print_heap(Q, printNode);
    //printf("Q.A: ");
    //for(int i = 0; i < G->N; ++i){
    //    Node aaa = ((Node) Q->A)[i];
    //    printf("[%d, %d] ", aaa.key, aaa.d);}
    //printf("\n");
    printf("G.V: ");
    for(int i = 0; i < G->N; ++i)
        printf("[%d, %d] ", G->V[i].key, G->V[i].d);
    printf("\n\n");
    while (!is_heap_empty(Q)) {   // One node u is extracted at each iteration
        Node* u = extract_min(Q);
        printf("Node %d, in graph: %p\n", u->key, &G->V[u->key]);
        ListNode* tmp = G->adjacencyList[u->key];
        while(tmp) {   // iterates on the adjacency list of u
            relax_heap(Q, &G->V[u->key], &G->V[(int)((Pair*)tmp->T)->a], (int)((Pair*)tmp->T)->b);
            //heapify(Q, 0);
            printf("\tInside while. Node %d, weigth %d (tmp)\n", ((Pair*)tmp->T)->a, ((Pair*)tmp->T)->b);
            printf("\tNodes. tmp: %d, v: %d\n", ((Pair*)tmp->T)->a, G->V[((Pair*)tmp->T)->a].key);
            decrease_key(Q, v, u->d + w);
            Node* v = &G->V[((Pair*)tmp->T)->a];
            int w = (int)((Pair*)tmp->T)->b;
            if(u->d + w < v->d){
                G->V[(int)((Pair*)tmp->T)->a].d = u->d + w;
            }
            printf("\tNode [%d, %d]. Graph node: [%d, %d]. Queue min node: [%d, %d]\n", v->key, v->d,
                                                            G->V[(int)((Pair*)tmp->T)->a].key, G->V[(int)((Pair*)tmp->T)->a].d,
                                                            ((Node*)min_value(Q))->key, ((Node*)min_value(Q))->d);
            print_heap(Q, printNode);
            printf("G.V: ");
            for(int i = 0; i < G->N; ++i)
                printf("[%d, %d] ", G->V[i].key, G->V[i].d);
            printf("\n\n");
            tmp = tmp->next;
        }
    }
}