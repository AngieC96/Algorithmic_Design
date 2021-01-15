# Binary Heaps: Homework 2



- *By modifying the code written during the last lessons, provide an array-based implementation of binary heaps which avoids to swap the elements in the array $\texttt{A}$.*
  *(**Hint**: use two arrays, $\texttt{key_pos}$ and $\texttt{rev_pos}$, of natural numbers reporting the position of the key of a node and the node corresponding to a given position, respectively)*

  <!--key_pos è un array di integer (ma potrebbe essere un array di puntatori, che forse è più facile da capire)-->
  <!--lo scopo è evitare di swappare elementi nell'array A, swappando invece gli elementi di key_pos (che essendo integer sono cheap da swappare, a differenza degli elementi di A che potrebbero essere strutture dati complesse e pesanti)-->
  <!--l'i-esimo elemento di key_pos è l'indice dell'elemento di A corrispondente all'i-esimo nodo nello heap-->
  <!--i-esimo nodo nello heap significa che devi scorrere lo heap "da sopra a sotto, da sinistra verso destra" e prendere l'i-esimo elemento che incontri (è lo stesso ordine con cui lo stampa la funzione print_heap)-->
  <!--quando devi swappare due elementi di A, non tocchi A ma invece swappi gli elementi di key_pos-->
  <!--dunque key_pos associa le posizioni nello heap alle corrispondenti chiavi in A; rev_pos fa esattamente l'operazione opposta-->
  <!--l'array rev_pos è necessario nella libreria binheap solo nella funzione decrease_key (per tutto il resto basterebbe key_pos)-->
  <!--key_pos → node $i$ of heap is in `key_pos[i]` in $A$-->
  <!--rev_pos → for $i$, node `A[i]` is in `rev_pos[i]` in heap-->
  <!--![6bcd84ad-9c39-439a-85fd-2bd5548d2afa](6bcd84ad-9c39-439a-85fd-2bd5548d2afa.jpeg!!!!)-->

  The solution can be found in the folder [04_Binary_heaps_noswap](../04_Binary_heaps_noswap).
  
- *Consider the next algorithm:*

  ```pseudocode
  def Ex2(A)
  	D ← build(A)
  	
  	while ¬ is_empty(D)
  		extract_min(D)
  	end while
  end def
  ```

  *where $\texttt{A}$ is an array. Compute the time-complexity of the algorithm when:*

  - $\texttt{build}$, $\texttt{is_empty} \in \Theta(1)$, $\texttt{extract_min} \in \Theta(|D|)$;
  - $\texttt{build} \in \Theta(|A|)$, $\texttt{is_empty} \in \Theta(1)$, $\texttt{extract_min} \in O(\log n)$;
  
  In the first case, the time complexity is $\Theta(1) + |D| \cdot \Theta(|D|) = \Theta(|D|^2)$, since $\texttt{build}$ costs $\Theta(1)$ and the while is repeated until $D$ is empty, so $|D|$ times, with inside $\texttt{extract_min}$ that costs $\Theta(|D|)$.
  
  In the second case, $\Theta(|A|) + |D| \cdot O(\log n) = O(|A| + |D|\log n)$, since $\texttt{build}$ costs $\Theta(|A|)$ and the while is repeated until $D$ is empty, so $|D|$ times, with inside $\texttt{extract_min}$ that costs $O(\log n)$.
