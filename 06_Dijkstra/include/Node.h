#ifndef __NODE__
#define __NODE__

/**
 * @file
 *
 * It will contain the Node-related code
 */

#include <stdlib.h>
#include <stdio.h>

/** @struct Node
 *  @brief A class to represent a node.
 *
 *  This class is meant to represent a node.
 */
typedef struct {
    /** @brief The keys are the identifyer of the Node. */
    int key;
    /** @brief The content of the Node (satellite data). */
    void* value;
    /** @brief The distance from the source s. */
    unsigned int d;
    /** @brief The predecessor of this Node in the shortest path from the source s. */
    struct Node* pred;
} Node;

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
 * @param node is a pointer to the node whose key should be decreased.
 * @param value is a pointer to the new value of the node's key.
 * @return a pointer to the node in which the new value is stored. If 
 *         either the new value is greater than of equal to the old key
 *         value or the node does not belong to the H, NULL is returned.
 **********************************************************************/
const Node* decrease_dist(Node* node, const int value);


/**********************************************************************
 * Prints the @ref Node.
 *
 * This function prints the content of the @ref Node.
 * The function key_printer is used to access the function to be used
 * for printing current @ref Node @ref value. Note that different data types
 * need different specifier in printf().
 *
 * @param n the @ref Node to be printed.
 * @param key_printer used to access the function to be used for printing 
 * current node data
 **********************************************************************/
void printNode(const Node* n, void (*key_printer)(const void *value));

#endif // __NODE__