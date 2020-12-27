#ifndef __LIST__
#define __LIST__

/**
 * @file
 *
 * It will contain the List-related code
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** @struct ListNode
 *  @brief A class to represent a node of a list.
 *
 *  This class is meant to represent a node of a list.
 */
typedef struct ListNode{
    /** @brief Value inside the list node: any data type can be stored in it. */
    void* T;
    /** @brief Pointer to the next element of the list. */
    struct ListNode* next;
} ListNode;

/**********************************************************************
 * Returns the tail of the list.
 *
 * This function returns the tail of the list by following all the 
 * pointers of the list nodes.
 *
 * @param l the list from which the tail should be returned.
 * @return a pointer to the tail of the list.
 **********************************************************************/
ListNode* tail(ListNode* l);

/**********************************************************************
 * Inserts an element at the end of the list.
 *
 * This function inserts an element at the end of the list.
 *
 * @param l the list.
 * @param value the value to be inserted in the list.
 * @return a pointer to the new node of the list.
 **********************************************************************/
ListNode* push_back(ListNode* l, const void* value);

/**********************************************************************
 * Prints the list.
 *
 * This function prints all the nodes contained in the list.
 * key_printer is used to access the function to be used for printing
 * current node data. Note that different data types need different
 * specifier in printf().
 *
 * @param l the list to be printed.
 * @param key_printer used to access the function to be used for printing 
 * current node data
 **********************************************************************/
void printList(const ListNode* l, void (*key_printer)(const void *value));

/**********************************************************************
 * Destructs a list.
 *
 * This function destructs a list.
 * 
 * @param l the list to be destructed.
 **********************************************************************/
void Ldestructor(ListNode* l);

#endif // __LIST__
