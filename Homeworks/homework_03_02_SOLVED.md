# Sorting: Homework 2

1. <a name="point1"></a> *Generalize the $\mathtt{SELECT}$ algorithm to deal also with repeated values and prove that it still belongs to $O(n)$.*

2. *Download the latest version of the code from*
                                         *https://github.com/albertocasagrande/AD_sorting*
*and*

- *Implement the $\texttt{SELECT}$ algorithm of Ex. [1](#point1).*
- *Implement a variant of the $\texttt{QUICK SORT}$ algorithm using above-mentioned $\texttt{SELECT}$ to identify the best pivot for partitioning.*
- *Draw a curve to represent the relation between the input size and the execution-time of the two variants of $\texttt{QUICK SORT}$ (i.e, those of Ex. 2 and Ex. 1 of [this file](#homework_03_01_SOLVED.md)) and discuss about their complexities.*

3. *(Ex. 9.3-1 in [[1]](#ref1)) In the algorithm $\texttt{SELECT}$, the input elements are divided into chunks of $5$. Will the algorithm work in linear time if they are divided into chunks of $7$? What about chunks of $3$?*

4. *(Ex. 9.3-5 in [[1]](#ref1) Suppose that you have a "black-box" worst-case linear-time subroutine to get the position in $A$ of the value that would be in position $n/2$ if $A$ was sorted. Give a simple, linear-time algorithm that solves the selection problem for an arbitrary position $i$.*

5. *Solve the following recursive equations by using both the recursion tree and the substitution method:*

  - $T_1(n) = 2 * T_1(n/2) + O(n)$

    Using the **recursion tree**, we have that, choosing $cn$ as representative for $O(n)$:
    $$
    \begin{align*}
    T_1(n) &= 2 * T_1(n/2) + O(n) \\
    &\le 2 * T_1(n/2) + cn \\
    &\le 2 * (2 * T_1(n/4) + cn/2) + cn \\
    &= 4 * T_1(n/4) + 2cn \\
    &\le 4 *(2 * T_1(n/8) + cn/4) + 2cn \\
    &= 8 * T_1(n/8) + 3cn\\
    &\le \ldots \\
    &\le 2^{\log_2 n} T_1(0) + \log_2 n * cn \\
    &= n * 0 + c n \log_2 n \in O(n \log n)
    \end{align*}
    $$
    or alternatively
    $$
    T_1(n) = 2 * T_1(n/2) + O(n) \le \sum_{i=0}^{\log_2 n} 2^i c \frac n{2^i} = \sum_{i=0}^{\log_2 n} cn = cn \sum_{i=0}^{\log_2 n} 1 = cn \log_2 n \in O(n \log n)
    \nonumber
    $$
    Using the **substitution method**, we guess that $T_1(n) \in O(n \log n)$. We select a representative for $O(n \log n)$ and $O(n)$, e.g. $cn \log n$ and $c' n$. We assume that $\forall m < n, \; T_1(m) \le cm \log m$. If this is the case,
    $$
    \begin{align*}
    T_1(n) &= 2 * T_1(n/2) + c'n \\
    &\le 2 * c n/2 \log(n/2) + c' n \\
    &\le cn (\log n - \log 2) + c'n \\
    &\le cn \log n - cn \log 2 + c'n
    \end{align*}
    $$
    if $c' n - cn \log 2 \le 0$, then $c' n \le cn \log 2 = cn$ so $c \ge c'$ then $T_1(n) \le c n \log n$. Thus we have proved by induction that $\forall n \in \mathbb{N}, \; T_1(n) \le c n \log n$ for a proper $c$. So $T_1(n) \in O(n \log n)$.

  - $T_2(n) = T_2(\lceil n/2 \rceil) + T_2(\lfloor n/2 \rfloor) + \Theta(1)$

    Using the **recursion tree**, we have that, choosing $c$ as representative for $O(1)$:
    $$
    \begin{align*}
    T_2(n) &= T_2(\lceil n/2 \rceil) + T_2(\lfloor n/2 \rfloor) + \Theta(1) \\
    &= T_2(\lceil n/2 \rceil) + T_2(\lfloor n/2 \rfloor) + c \\
    &= (T_2(\lfloor n/2 \rfloor) + T_2(\lfloor \lceil n/2 \rceil/2 \rfloor) + c) + (T_2(\lceil \lfloor n/2 \rfloor/2 \rceil) + T_2(\lfloor \lfloor n/2 \rfloor/2 \rfloor) + c) + c
    \end{align*}
    $$

    if $n$ is even then we can simply remove the floor and ceiling functions, if $n$ is odd instead, so if $n = m+1$ with $m$ even, we have that
    $$
    \left\lceil \frac{\lfloor n/2 \rfloor}2 \right\rceil = \left\lceil \left(\frac m2 +1 \right)/2 \right\rceil = \left\lceil \frac m4 + \frac12 \right\rceil = \left\lceil \frac m4 + \frac14 \right\rceil = \left\lceil \frac{m+1}4 \right\rceil = \left\lceil \frac n4 \right\rceil \\
    \left\lfloor \frac{\lceil n/2 \rceil}2 \right\rfloor = \left\lfloor \left(\frac m2 +1 \right)/2 \right\rfloor = \left\lfloor \frac m4 + \frac12 \right\rfloor = \left\lceil \frac m4 \right\rceil = \left\lceil \frac n4 \right\rceil \\
    \left\lceil \frac{\lfloor n/2 \rfloor}2 \right\rceil = \left\lceil \left(\frac m2 \right)/2 \right\rceil =  \left\lceil \frac m4 \right\rceil = \left\lceil \frac m4 + \frac 14 \right\rceil = \left\lceil \frac{m+1}4 \right\rceil = \left\lceil \frac n4 \right\rceil \\
    \left\lfloor \frac{\lfloor n/2 \rfloor}2 \right\rfloor = \left\lfloor \left(\frac m2 \right)/2 \right\rfloor =  \left\lfloor \frac m4 \right\rfloor = \left\lfloor \frac m4 + \frac 14 \right\rfloor = \left\lfloor \frac{m+1}4 \right\rfloor = \left\lfloor \frac n4 \right\rfloor
    \nonumber
    $$

    or alternatively

    ==the tree is complete up to the length of the shortest branch (which is the rightmost)==

    ...

    Using the **substitution method**, we want to prove that $T_2 \in O(n)$. We select a function in $O(n)$, $cn$, and we select a representative of $\Theta(1)$, $c'$. Inductive assumption: we assume that $\forall m < n, \; T_2(m) \le cm$. We want to prove that $\forall n, \; T_2(n) \le cn$.
    $$
    \begin{align*}
    T_2(n) &= T_2(\lceil n/2 \rceil) + T_2(\lfloor n/2 \rfloor) + \Theta(1) \\
    &\le T_2(\lceil n/2 \rceil) + T_2(\lfloor n/2 \rfloor) + c' \\
    &\le c \lceil n/2 \rceil + c \lfloor n/2 \rfloor + c' \\
    &\le c(\lceil n/2 \rceil + \lfloor n/2 \rfloor) + c' \\
    &\le cn + c'
    \end{align*}
    $$

    But this is **not** what we wanted to prove, we cannot conclude anything! This doesn't prove $T_2 \in O(n)$ because $cn + c' \not\le cn$: but we are not able to prove it for a term of lower order. The problem is that we selected the wrong representative for $O(n)$, let us choose $cn - d \in O(n)$. Inductive assumption: we assume that $\forall m < n, \; T_2(m) \le cm - d$. We want to prove that $\forall n, \; T_2(n) \le cn - d$.
    $$
    \begin{align*}
    T_2(n) &= T_2(\lceil n/2 \rceil) + T_2(\lfloor n/2 \rfloor) + \Theta(1) \\
    &\le T_2(\lceil n/2 \rceil) + T_2(\lfloor n/2 \rfloor) + c' \\
    &\le c \lceil n/2 \rceil - d + c \lfloor n/2 \rfloor - d + c' \\
    &\le c(\lceil n/2 \rceil + \lfloor n/2 \rfloor) - 2d + c' \\
    &\le cn -2d + c'
    \end{align*}
    $$
    If $c' - d \le 0$, then $T_2(n) \le cn - d$. Thus we have proved by induction that $\forall n \in \mathbb{N}, \; T_1(n) \le c n - d$ for proper $c$ and $d$. So $T_1(n) \in O(n)$.

    Now we want to prove that $T_2(n) \in \Omega(n)$. We select the representative $cn \in \Omega(n)$ and the representative $c' \in \Theta(1)$. Inductive assumption: we assume that $\forall m < n, \; T_2(m) \ge cm$. We want to prove that $\forall n, \; T_2(n) \ge cn$.
    $$
    \begin{align*}
    T_2(n) &= T_2(\lceil n/2 \rceil) + T_2(\lfloor n/2 \rfloor) + \Theta(1) \\
    &\ge T_2(\lceil n/2 \rceil) + T_2(\lfloor n/2 \rfloor) + c' \\
    &\ge c \lceil n/2 \rceil + c \lfloor n/2 \rfloor + c' \\
    &\ge c(\lceil n/2 \rceil + \lfloor n/2 \rfloor) + c' \\
    &\ge cn + c' \\
    &\ge cn
    \end{align*}
    $$
    Thus we have that $T_2(n) \ge cn$, so we have proved by induction that  for a proper $c$. Then $T_2(n) \in \Omega(n)$. Therefore we have proved that $T_2(n) \in \Theta(n)$.

    By using substitution method, you can prove that $T_2(n) \in O(n^2)$. This is not wrong, because $O(n) \subseteq O(n^2)$, however this is a curse complexity bound.

  - $T(n) = T\left( \frac 15 n \right) + T \left(\frac34 n \right) + \Theta(n)$

    This equation is weird because it is totally unbalanced! All the branches are different in length! Let's call $\alpha = \frac 15$ and $\beta = \frac 34$. On the $i$-th level all the nodes contains $\alpha^j \beta^{i-j}$; the number of nodes on the $i$-th level having $\alpha^j \beta^{i-j}$ elements to deal with is the number of possible way in which we can select $j$ left moves over $i$ total moves: so $\binom i j$ moves in total. Thus at each level $i$ we have
    $$
    \sum_{j=0}^i \binom i j \alpha^j \beta^{i-j} n
    \nonumber
    $$
    So this is the total number of elements we need to deal with at the $i$-th level of our recursion tree. We have that
    $$
    \sum_{j=0}^i \binom i j \alpha^j \beta^{i-j} n = (\alpha + \beta)^i \cdot n
    \nonumber
    $$
    To do an over approximation of the complexity, let's suppose that the tree has infinite length. So
    $$
    T(n) \le \sum_{i=0}^\infty (\alpha + \beta)^i \cdot n = \sum_{i=0}^\infty \left(\frac 15 + \frac 34 \right)^i \cdot n = \sum_{i=0}^\infty \left(\frac {19}{20} \right)^i \cdot n.
    \nonumber
    $$
    Because of the convergence of geometric series $\left( \frac{19}{20} < 1 \right)$ $T(n) \le \frac 1{1-\frac{19}{20}}n = 20n$, so $T(n) \in O(n)$.

    Can we lower bound it? Of course yes, since just the first call of our recursive call costs $\Theta(n)$, so $T(n) \in \Omega(n)$. Thus $T(n) \in \Theta(n)$.

    So just soling this problem we proved a new theorem:

    > **Theorem:** Let $\alpha$ and $\beta$ be two natural numbers. If $\alpha + \beta < 1$, then $T(n) = T(\alpha n) + T(\beta n) + \Theta(n)$ belongs to $\Theta(n)$.

  - $T_3(n) = 3 * T_3(n/2) + O(n)$

    

  - $T_4(n) = 7 * T_4(n/2) + \Theta(n^2)$



### References

<a name="ref1"></a> [1] T.H. Cormen, C.E. Leiserson, R.L. Rivest, and C. Stein. *Introduction to Algorithms*. The MIT Press. MIT Press, 2009.