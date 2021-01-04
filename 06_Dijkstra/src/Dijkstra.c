#include <Dijkstra.h>

// #define INFTY 99999999

z

// relax(Q, v, u, w)
// {
//     if(u.d + w < v.d){
//         decrease_key(Q, v, u.d + w);
//     }
// }

// dijkstra(G, s)
// {
//     init_sssp(G, s);
//     s.d = 0;
    
//     PriorityQueue *Q = build_queue(sizeof(Node));
//     Q <- G.V;  // All the nodes are in Q at the beginning of the computation
//     while (!is_queue_empty(Q))  // One node u is extracted at each iteration
//     {
//         u = extract_min(Q);
//         for (v, w) in G.Adj(u){  // iterates on the adjacency list of u
//             relax(Q, u, v, w);
//         }
//     }
    

// }