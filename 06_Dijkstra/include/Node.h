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
    /** @brief The content of the Node. */
    void* value;
    /** @brief The distance from the source s. */
    int d;
    /** @brief The predecessor of this Node in the shortest path from the source s. */
    struct Node* pred;
} Node;


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