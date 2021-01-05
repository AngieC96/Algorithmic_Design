#ifndef __APQUEUE__
#define __APQUEUE__

/**
 * @file
 *
 * It will contain the array-based Min Priority Queue related code
 */

#include <stdlib.h>

#include "List.h"
#include "utilities.h"


typedef struct {
    /** @brief Array containing the values. */
    int* array;
    /** @brief Number of elements in the array. */
    int n;
} ArrayPriorityQueue;


/**********************************************************************
 * Builds a priority queue.
 *
 * This function creates an empty priority queue.
 *
 * @param elem_size is the size of the type that the queue will contain.
 * @return the priority queue just created.
 **********************************************************************/
PriorityQueue* build_queue(size_t elem_size);

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
int is_queue_empty(const PriorityQueue *Q);

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
const void* minimum(PriorityQueue *Q);

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
const QueueNode* extract_min(PriorityQueue *Q);

/**********************************************************************
 * Decrease the value of node's key.  !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
 *
 * This function decreases the value of a node's key and returns a 
 * pointer to the node in which the new value is stored. If either the 
 * new value is greater than of equal to the old key value or the node 
 * does not belong to the considered heap, the heap remains unchanged 
 * and NULL is returned. The asymptotic time-complexity of this 
 * function is O(log n).
 *
 * @param H is the heap in which the key value should be decreased.
 * @param node is a pointer to the node whose key should be decreased.
 * @param value is a pointer to the new value of the node's key.
 * @return a pointer to the node in which the new value is stored. If 
 *         either the new value is greater than of equal to the old key
 *         value or the node does not belong to the H, NULL is returned.
 **********************************************************************/
const QueueNode* decrease_key(PriorityQueue* Q, QueueNode* node, const size_t value);

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
const void *insert_value(PriorityQueue* Q, const void* value, size_t priority);

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
void print_pqueue(const PriorityQueue* Q, void (*key_printer)(const void *value));

#endif // __APQUEUE__