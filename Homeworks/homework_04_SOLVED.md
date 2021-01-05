# Weighted Graphs: Homework

- *Implement the array-based version of the Dijkstra’s algorithm.*

  We maintain the min-priority queue by taking advantage of the vertices being numbered $1$ to $|V|$. We simply store $v.d$ in the $v$-th entry of an array. Each $\texttt{INSERT}$ and $\texttt{DECREASE_KEY}$ operation takes $O(1)$ time, and each $\texttt{EXTRACT_MIN}$ operation takes $O(V)$ time (since we have to search through the entire array), for a total time of $O(V^2 + E) = O(V^2)$.

- *Implement the binary heap-based version of the Dijkstra’s algorithm by using the library `binheap` that was developed during [Lesson 6](https://www.youtube.com/watch?v=TyHUQ1nn8WM), [Lesson 7](https://www.youtube.com/watch?v=lWFAPkgZ_7Q), and [Lesson 8](https://www.youtube.com/watch?v=4BnGCXzkFbo).*

  <img src=".images/homework_04_SOLVED/image-20210104202450014.png" alt="image-20210104202450014" style="zoom:60%;" />

- *Test the implementations on a set of instances of the problem and compare their execution times.*