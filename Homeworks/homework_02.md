# Binary Heaps: Homework 2



- *Implement the array-based representation of binary heap together with the functions $\texttt{HEAP_MIN}$, $\texttt{REMOVE_MIN}$, $\texttt{HEAPIFY}$, $\texttt{BUILD_HEAP}$, $\texttt{DECREASE_KEY}$, and $\texttt{INSERT_VALUE}$.*

  The solution can be found in the file `binheap.c` in the folder [Binary_heaps](../Binary_heaps), with the corresponding names `min_value`, `extract_min`, `heapify`, `build_heap`, `decrease_key` and `insert_value`. The functions `is_heap_empty`, `swap_keys`, `find_the_max`, `delete_heap`, and `print_heap` are also added.

- *Implement an iterative version of $\texttt{HEAPIFY}$.*

  The solution can be found in the function `heapify`, contained in the file `binheap.c` in the folder [Binary_heaps](../Binary_heaps).

- Test the implementation on a set of instances of the problem and evaluate the execution time.

  In the following graph we can see the execution time of the program `test_delet_min`:

- (Ex. 6.1-7 in [1]) Show that, with the array representation, the leaves of a binary heap containing $n$ nodes are indexed by $\lfloor n/2 \rfloor + 1, \lfloor n/2 \rfloor + 2, \ldots, n$.

- (Ex. 6.2-6 in [1]) Show that the worst-case running time of $\texttt{HEAPIFY}$ on a binary heap of size $n$ is $\Omega(\log n)$.
  (*Hint*: For a heap with $n$ nodes, give node values that cause $\texttt{HEAPIFY}$ to be called recursively at every node on a simple path from the root down to a leaf.)

- (Ex. 6.3-3 in [1]) Show that there are at most $\lceil n/2^{h+1} \rceil$ nodes of height $h$ in any $n$-element binary heap.

- By modifying the code written during the last lessons, provide an array-based implementation of binary heaps which avoids to swap the elements in the array $\texttt{A}$.
  (*Hint*: use two arrays, $\texttt{key_pos}$ and $\texttt{rev_pos}$, of natural numbers reporting the position of the key of a node and the node corresponding to a given position, respectively)

- Consider the next algorithm:

  ```
  def Ex2 ( A )
  	D ← build ( A )
  	
  	while ¬ is_empty ( D )
  		extract_min ( D )
  	endwhile
  enddef
  ```

  where $\texttt{A}$ is an array. Compute the time-complexity of the algorithm when:

  - $\texttt{build}$, $\texttt{is_empty} \in \Theta(1)$, $\texttt{extract_min} \in \Theta(|D|)$;
  - $\texttt{build \in \Theta(|A|)}$, $\texttt{is_empty} \in \Theta(1)$, $\texttt{extract_min} \in O(\log n)$;

### References

[1] T.H. Cormen, C.E. Leiserson, R.L. Rivest, and C. Stein. *Introduction to Algorithms*. The MIT Press. MIT Press, 2009.