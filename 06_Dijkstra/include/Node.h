#ifndef __NODE__
#define __NODE__

/**
 * @file
 *
 * It will contain the Node-related code
 */

#include <stdlib.h>

/** @struct Node
 *  @brief A class to represent a node.
 *
 *  This class is meant to represent a node.
 */
typedef struct {
    /** @brief The keys are the identifyer of the Node. */
    int key;
    /** @brief What is stored into the Node. */
    void *value;
    /** @brief The size of the @ref value type. */
    size_t value_size;
} Node;

#endif // __NODE__