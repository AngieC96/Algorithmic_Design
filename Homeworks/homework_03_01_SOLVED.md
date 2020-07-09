# Sorting: Homework



- *By using the code at:*

  ​                                         https://github.com/albertocasagrande/AD_sorting

  *implement Insertion Sort, Quick Sort, Bubble Sort, Selection Sort, and Heap Sort.*

  The solution with the implemented cod can be found in the files `insertion_sort.c`, `quick_sort.c`, `bubble_sort.c`, `selection_sort.c`, `heap_sort.c` in the folder [Sorting](../Sorting).

- *For each of the implemented algorithm, draw a curve to represent the relation between the input size and the execution-time.*

  For **Insertion sort** we have:

  <img src="figs/insertion_sort.png" alt="insertion_sort" style="zoom:50%;" />

  For **Quick sort** we have

  

- *Argue about the following statement and answer the questions*

  1. *Heap Sort on a array $A$ whose length is n takes time $O(n)$.*
  2. *Heap Sort on a array $A$ whose length is n takes time $\Omega(n)$.*
  3. *What is the worst case complexity for Heap Sort?*
  4. *Quick Sort on a array A whose length is n takes time $O(n^3)$.*
  5. *What is the complexity of Quick Sort?*
  6. *Bubble Sort on a array A whose length is n takes time $\Omega(n)$.*
  7. *What is the complexity of Bubble Sort?*

- *Solve the following recursive equation:*
  $$
  T(n) = \begin{cases}
  \Theta(1) & \text{if } n = 32 \\
  3 * T \left( \frac n 4 \right) + \Theta (n^{3/2}) & \text{otherwise}
  \end{cases}
  \nonumber
  $$
  Using the **recursion tree**, we have that our stopping condition is when $n = 32$, so when in our recursion $\frac n{4^i} = 32 \Longleftrightarrow n = 2^5 \cdot 2^{2i} \Longleftrightarrow n = 2^{5 + 2i} \Longleftrightarrow i = \frac{\log_2 n - 5}2$ and choosing $cn^{3/2}$ as representative for $\Theta(n^{3/2})$ we have that
  $$
  \begin{align*}
  T(n) &= 3 * T\left(\frac n4 \right) + \Theta(n^{3/2}) \\
  &\le 3 * T\left( \frac n4 \right) + cn^{3/2} \\
  &\le 3 * \left(3 * T\left(\frac n{16} \right) + c \left(\frac n4 \right)^{3/2} \right) + cn^{3/2} \\
  &= 9 * T\left( \frac n{16} \right) + 3c \left(\frac n4 \right)^{3/2} + cn^{3/2} \\
  &\le 9 * \left(3 * T\left( \frac n{64}\right) + c \left(\frac n{16} \right)^{3/2} \right) + 3c \left(\frac n4 \right)^{3/2} + cn^{3/2} \\
  &\le 27 * T\left( \frac n{64}\right) + 9c \left(\frac n{16} \right)^{3/2} + 3c \left(\frac n4 \right)^{3/2} + cn^{3/2} \\
  &\le \ldots \\
  &\le 3^{ \frac{\log_2 n - 5}2} T(32) + \sum_{i=0}^{\log_2 n} 3^i c \left(\frac n{4^i} \right)^{3/2}
  = 3^{ \frac{\log_2 n - 5}2} \Theta(1) + \sum_{i=0}^{ \frac{\log_2 n - 5}2} 3^i c \frac{n^{3/2}}{4^{3/2i}} \\
  &\le 3^{ \frac{\log_2 n - 5}2} c' + \sum_{i=0}^{ \frac{\log_2 n - 5}2} \frac{3^i}{2^{3i}} c n^{3/2}
  = 3^{ \frac{\log_2 n - 5}2} c' + c n^{3/2} \sum_{i=0}^{ \frac{\log_2 n - 5}2} \left(\frac{3}{2^{3}} \right)^i \\
  &= 3^{ \frac{\log_2 n - 5}2} c' + cn^{3/2} \cdot \frac{(3/8)^{\left(\frac{\log_2 n - 5}2\right)+1} - 1}{3/8-1}
  = 3^{ \frac{\log_2 n - 5}2} c' + cn^{3/2} \cdot \frac{(3/8)^{\frac{\log_2 n - 3}2} - 1}{(3-8)/8} \\
  &= 3^{ \frac{\log_2 n - 5}2} c' -\frac85 cn^{3/2} \cdot \frac{3^{\frac{\log_2 n - 3}2} - 8^{\frac{\log_2 n - 3}2}}{8^{\frac{\log_2 n - 3}2}}
  \end{align*}
  $$
  since $3^{\frac{\log_2 n - 3}2} = (3^{\log_2 n - 3})^{1/2} = \left(\frac{3^{\log_2 n}}{3^3}\right)^{1/2} = \left(\frac{3^{\log_2 3 \log_3 n}}{3^3}\right)^{1/2} = \left(\frac{n^{\log_2 3}}{3^3}\right)^{1/2} = \frac{n^{\frac{\log_2 3}2}}{3^{3/2}}$ (since $\log_b n = \log_b a \cdot \log_a n$ we have $\log_2 n = \log_2 3 \cdot \log_3 n$) and $8^{\frac{\log_2 n - 3}2} = 2^{\frac32(\log_2 n - 3)} = (2^{\log_2 n - 3})^{3/2} = \left(\frac{2^{\log_2 n}}{2^3} \right)^{3/2} = \left(\frac{n}{8} \right)^{3/2}$ we have that
  $$
  \begin{align*}
  &= \frac{n^{\frac{\log_2 3}2}}{3^{3/2}} c' -\frac85 cn^{3/2} \cdot \frac{\frac{n^{\frac{\log_2 3}2}}{3^{3/2}} - (n/8)^{3/2}}{(n/8)^{3/2}} 
  = \frac{n^{\frac{\log_2 3}2}}{3^{3/2}} c' -\frac85 8^{3/2} cn^{3/2} \cdot \frac{\frac{n^{\frac{\log_2 3}2}}{3^{3/2}} - \frac{n^{3/2}}{8^{3/2}}}{n^{3/2}} \\
  &= \frac{n^{\frac{\log_2 3}2}}{3^{3/2}} c' -\frac85 8^{3/2} c \cdot \left(\frac{n^{\frac{\log_2 3}2}}{3^{3/2}} - \frac{n^{3/2}}{8^{3/2}} \right)
  = \frac{n^{\frac{\log_2 3}2}}{3^{3/2}} c' -\frac85 8^{3/2} c \cdot \frac{n^{\frac{\log_2 3}2}}{3^{3/2}} + \frac85 8^{3/2} c\frac{n^{3/2}}{8^{3/2}}\\
  &= \frac{n^{\frac{\log_2 3}2}}{3^{3/2}} \left( c' -\frac{8^{5/2}}5 c \right) + \frac85 c n^{3/2}
  \in O(n^{3/2})
  \end{align*}
  $$
  So we have that $T(n) \in O(n^{3/2})$. Since all the inequalities work also with the $\ge$ , we have that $T(n) \in \Omega(n^{3/2})$, so we have that $T(n) \in \Theta(n^{3/2})$

