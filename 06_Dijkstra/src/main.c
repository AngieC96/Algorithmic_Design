#include <stdio.h>

#include "List.h"
#include "PriorityQueue.h"
#include "utilities.h"

#define int_t(i) *((const int *)i)
#define float_t(f) *((const float *)f)


int main(int argc, char *argv[])
{
    ListNode *list = NULL;
    printf("Void list: %p\n", list);
    // Create and print an int linked list
    int arr[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < 5; ++i)
       list = push_back(list, &arr[i]);
       //push_back(list, &arr[i]);
    printf("Value in head: %d\n", int_t(list->T));
    printf("Value in head+1: %d\n", int_t(list->next->T));
    int x = 60, y=70;
    push_back(list, &x);
    push_back(list, &y);
    printList(list, int_printer);
    
    // Create and print a float linked list 
    ListNode* list2 = NULL;
    float arr2[] = {10.1, 20.2, 30.3, 40.3, 50.5};
    for (int i = 0; i < 5; ++i)
        push_back_void(&list2, &arr2[i]);
    printf("Value in head: %.2f\n", float_t(list2->T));
    printf("Value in head+1: %.2f\n", float_t(list2->next->T));
    printList(list2, float_printer);

    Ldestructor(&list);
    Ldestructor(&list2);
    printf("Destroyed list: %p\n", list);


    return 0;
}