#ifndef __PQUEUE__
#define __PQUEUE__

/**
 * @file
 *
 * It will contain the Priority Queue-related code
 */

#include <stdlib.h>

#include "List.h"
#include "utilities.h"

/** @struct ListNode
 *  @brief A class to represent a node of a list.
 *
 *  This class is meant to represent a node of a list.
 */
typedef struct QueueNode{
    /** @brief Value inside the list node: any data type can be stored in it. */
    void* T;
    /** @brief Priority of the node: ower values indicate higher priority  (no negative edges so no negative distances = priorities). */
    size_t priority;
    /** @brief Pointer to the next element of the list. */
    struct QueueNode* next;
} QueueNode;

/** @struct PriorityQueue
 *  @brief A class to represent a priority queue.
 *
 *  This class is meant to represent a priority queue.
 */
typedef struct {
    /** @brief The list used to store the queue elements. */
    QueueNode* head;
    /** @brief The type size in bytes of the elements in Q. */
    size_t elem_size;
} PriorityQueue;


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
 * Returns the tail of the priority queue.
 *
 * This function returns the tail of the priority queue.
 *
 * @param Q is the queue whose tail has to be found.
 * @return the tail of the queue.
 **********************************************************************/
QueueNode* Qtail(PriorityQueue* Q);

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
const QueueNode* extract_min_pq(PriorityQueue *Q);

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
const QueueNode* decrease_key_pq(PriorityQueue* Q, QueueNode* node, const size_t value);

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
const void *insert_value_pq(PriorityQueue* Q, const void* value, size_t priority);

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

#endif // __PQUEUE__