#ifndef __APQUEUE__
#define __APQUEUE__

/**
 * @file
 *
 * It will contain the array-based Min Priority Queue related code.
 */

#include <stdlib.h>

#include "Node.h"
#include "Graph.h"
#include "utilities.h"


typedef struct {
    /** @brief Array containing the values. */
    Node** array;
    /** @brief Number of elements in the array. */
    int num_of_elem;
    int dim_queue;
} ArrayPriorityQueue;


/**********************************************************************
 * Builds an array-based priority queue.
 *
 * This function creates an empty priority queue.
 *
 * @param elem_size is the size of the type that the queue will contain.
 * @return the priority queue just created.
 **********************************************************************/
ArrayPriorityQueue* build_arrayQueue(Graph* G);

/**********************************************************************
 * Test whether the priority queue is empty.
 *
 * This function tests whether a priority queue is empty. If it is the 
 * case, it returns a value different from 0, otherwise, 0 is returned. 
 * The asymptotic time-complexity of this function is Theta(1).
 *
 * @param Q is the queue whose emptyness has to be tested.
 * @return the function returns 0 if Q is not empty; a number different 
 *         from 0 otherwise.
 **********************************************************************/
int is_arrayQueue_empty(const ArrayPriorityQueue *Q);

/**********************************************************************
 * Retruns the minimum from the heap. !!!!!!!!!!!!!!!!!!!!!!!!
 *
 * This function retruns the minimum value in the heap w.r.t. its 
 * total order. If the heap is empty, the heap is left unchanged
 * and NULL ???? is returned.
 *
 * @param H is the heap from which the minimum should be returned.
 * @return the minimum in the heap, if H is not empty; 
 *         NULL otherwise.????
 **********************************************************************/
int minimum_arrayQueue(ArrayPriorityQueue *Q);

/**********************************************************************
 * Extract the minimum from the heap and return a pointer to it. !!!!!!!!!!!!!!!!!!!!!!!!
 *
 * This function extracts the minimum value in the heap w.r.t. its 
 * total order and returns a pointer to it. If the heap is empty, the 
 * heap is left unchanged and NULL is returned. The asymptotic 
 * time-complexity of this function is O(log n).
 *
 * @param H is the heap from which the minimum should be extracted.
 * @return a pointer to the minimum in the heap, if H is not empty; 
 *         NULL otherwise.
 **********************************************************************/
Node* extract_min_arrrayQueue(ArrayPriorityQueue *Q);

/**********************************************************************
 * Insert a value in the heap.   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *
 * This function creates a new node and inserts the passed value as the
 * key of it. The function returns a pointer to the new node. If the 
 * heap already contains the maximum number of admissible nodes, then 
 * the heap remains unchanged and NULL is returned. The asymptotic 
 * time-complexity of this function is O(log n).
 *
 * @param H is the heap in which the key value should be decreased.
 * @param node is a pointer to the node whose key should be decreased.
 * @param value is a pointer to the new value of the node's key.
 * @return a pointer to the node in which the new value is stored. If 
 *         either the new value is greater than of equal to the old key
 *         value or the node does not belong to the H, NULL is returned.
 **********************************************************************/
void insert_value_arrrayQueue(ArrayPriorityQueue* Q, Node* n);

/**********************************************************************
 * Print a representation of the heap on the standard output.
 *
 * This function print a representation of the heap on the standard 
 * output. Since key type is unknown, a function to print a key value 
 * is required. The asymptotic time-complexity of this function is 
 * Theta(n).
 *
 * @param H is the heap in which the key value should be decreased.
 * @param key_printer is a function to print a key value.
 **********************************************************************/
void printQueue(const ArrayPriorityQueue* Q, void (*key_printer)(const void *value));

#endif // __APQUEUE__