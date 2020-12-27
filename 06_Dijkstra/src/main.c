#include <stdio.h>

#include "List.h"
#include "PriorityQueue.h"
#include "utilities.h"

#define int_t(i) *((const int *)i)
#define float_t(f) *((const float *)f)


int main(int argc, char *argv[])
{
    ListNode *list = NULL; 
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
    
//     List* list2 = (List*) malloc(sizeof(List));
//     // IMPORTANT! You have to set at least head = NULL in the defintion of the struct, otherwise you're pointing shit! Not possible if Angela uses typedef
//     list2->head = NULL;    // or (List*)NULL, it gets recast anyway
//     list2->elem_size = sizeof(int);
//     printf("HEAD: %p\n", list2->head);
//     printf("TAIL: %p\n\n", tail(list2));
//     //printf("TAIL content: %d\n", *((const int *)tail(list2)->T));  // Segmentation fault (core dumped)
//     printList(list2, int_printer);
//     list2->head = start;
//     list2->elem_size = sizeof(int);
//     printf("start address: %p\n", &start);
//     printf("head address: %p\n", &list2->head);
//     printf("start: %p\n", start);
//     printf("head: %p\n", list2->head);
//     printf("Value in start: %d\n", *((const int *)start->T));
//     printf("Value in head: %d\n", *((const int *)list2->head->T));
//     printf("Value in head: ");
//     int_printer(list2->head->T);
//     printf("\nTAIL: %d\n", *((const int *)tail(list2)->T));
// //    printf("HEAD: %d\n", list2->head);
//     printList(list2, int_printer);
//     push_back(list2, &y);  // insert 70
//     printList(list2, int_printer);
//     free(tail(list2)->T);  // the malloc is only in the value T!
//     printList(list2, int_printer);
    
//     printf("\npush_back:\n");
//     List* list3 = (List*) malloc(sizeof(List));
//     list3->head = NULL;
//     list3->elem_size = sizeof(int);
//     printf("\nTAIL: %p\n", tail(list2)->next);
//     for (int i=4; i>=0; i--)
//       push_back(list3, &arr[i]);
//     printList(list3, int_printer);

//     Ldestructor(list2);
//     Ldestructor(list3);
//     printf("Non funziona\n");
  


//     // Create and print a float linked list 
//     List* list4 = (List*) malloc(sizeof(List));
//     list4->head = NULL;
//     list4->elem_size = sizeof(float);
//     printList(list4, float_printer);
//     float arr2[] = {10.1, 20.2, 30.3, 40.4, 50.5}; 
//     for (i=4; i>=0; i--){
//         printf("Ciao\n");
//         push_back(list4, &arr2[i]);
//     }
//     printf("\n\nCreated float linked list is \n"); 
//     printList(list4, float_printer);
//     Ldestructor(list4);

    return 0;
}
