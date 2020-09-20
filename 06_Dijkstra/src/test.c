#include <stdio.h>

#include "List.h"
#include "PriorityQueue.h"
#include "utilities.h"

#define int_t(i) *((const int *)i)
#define float_t(f) *((const float *)f)


void push(struct ListNode** head_ref, void *new_data, size_t data_size)
{
    // Allocate memory for node
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
  
    new_node->T  = malloc(data_size);
    new_node->next = (*head_ref);
  
    // Copy contents of new_data to newly allocated memory.
    // Assumption: char takes 1 byte.
    int i;
    for (i=0; i<data_size; i++)
        *(char *)(new_node->T + i) = *(char *)(new_data + i);
  
    // Change head pointer as new node is added at the beginning
    (*head_ref)    = new_node;
}


/* Function to print nodes in a given linked list. fpitr is used
   to access the function to be used for printing current node data.
   Note that different data types need different specifier in printf() */
void printNode(struct ListNode *node, void (*key_printer)(const void *value))
{
    while (node != NULL)
    {
        key_printer(node->T);
        node = node->next;
    }
}


int main(int argc, char *argv[])
{
    printf("Ciao! Pollo\n");

//    ListNode* l = (ListNode*) malloc(sizeof(ListNode));
//    l->T = 1; // assignment makes pointer from integer without a cast
//    ListNode* h = (ListNode*) malloc(sizeof(ListNode));
//    l->next = h;
//    h->T = 2;
//    h->next = (ListNode*) malloc(sizeof(ListNode));
//    (h->next)->T = 3;

//    printf("%d\n", *((const int*) l->T));
//    printf("%d\n", *((const int*) h->T));
//    printf("%d\n", *((const int*) l->next->next->T));

    List* list = (List*) malloc(sizeof(List));
    printf("Before\n");
    list->head = NULL;
    list->elem_size = sizeof(int);
    printf("Before push_back\n");
    printf("TAIL: %p\n\n", tail(list));
//    int arr[] = {10, 20, 30, 40, 50}, i; 
//    for (i=4; i>=0; i--) 
//       push_back(list,  &arr[i]);
//    printList(list, int_printer);

//    free(l);
//    free(h);

    struct ListNode *start = NULL; 
  
    // Create and print an int linked list 
    unsigned int_size = sizeof(int); 
    int arr[] = {10, 20, 30, 40, 50}, i; 
    for (i=4; i>=0; i--) 
       push(&start, &arr[i], int_size);
    int x = 60, y=70;
    push(&start, &x, int_size);
    printf("Created integer linked list is \n"); 
    printNode(start, int_printer);
    printf("\nValue in start: %d\n", *((const int *)start->T));

    
    printf("\n\nCreated list:\n");
    List* list2 = (List*) malloc(sizeof(List));
    // IMPORTANT! You have to set at least head = NULL in the defintion of the struct, otherwise you're pointing shit! Not possible if Angela uses typedef
    list2->head = NULL;    // or (List*)NULL, it gets recast anyway
    list2->elem_size = sizeof(int);
    printf("HEAD: %p\n", list2->head);
    printf("TAIL: %p\n\n", tail(list2));
    //printf("TAIL content: %d\n", *((const int *)tail(list2)->T));  // Segmentation fault (core dumped)
    printList(list2, int_printer);
    list2->head = start;
    list2->elem_size = sizeof(int);
    printf("start address: %p\n", &start);
    printf("head address: %p\n", &list2->head);
    printf("start: %p\n", start);
    printf("head: %p\n", list2->head);
    printf("Value in start: %d\n", *((const int *)start->T));
    printf("Value in head: %d\n", *((const int *)list2->head->T));
    printf("Value in head: ");
    int_printer(list2->head->T);
    printf("\nTAIL: %d\n", *((const int *)tail(list2)->T));
//    printf("HEAD: %d\n", list2->head);
    printList(list2, int_printer);
    push_back(list2, &y);
    printList(list2, int_printer);
    
    printf("\npush_back:\n");
    List* list3 = (List*) malloc(sizeof(List));
    list3->head = NULL;
    list3->elem_size = sizeof(int);
    printf("\nTAIL: %p\n", tail(list2)->next);
    for (i=4; i>=0; i--)
      push_back(list3, &arr[i]);
    printList(list3, int_printer);

    free(list);
    free(list2);
    free(list3);
  


    // Create and print a float linked list 
    List* list4 = (List*) malloc(sizeof(List));
    list4->head = NULL;
    list4->elem_size = sizeof(float);
    float arr2[] = {10.1, 20.2, 30.3, 40.4, 50.5}; 
    for (i=4; i>=0; i--) 
       push_back(list4, &arr2[i]); 
    printf("\n\nCreated float linked list is \n"); 
    printList(list4, float_printer);
    free(list4);


    printf("\n\nPRIORITY QUEUE\n");
    PriorityQueue* Q = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    Q->head = NULL;
    Q->elem_size = sizeof(int);
    printf("\nTests on is_queue_empty\n");
    printf("Is queue empty? %d\n", is_queue_empty(Q));
    Q->head = (QueueNode*) malloc(sizeof(QueueNode));
    Q->head->T = &arr[0];  // 10
    Q->head->priority = arr[0];
    Q->head->next = (QueueNode*) malloc(sizeof(QueueNode));
    Q->head->next->T = &arr[1];  // 20
    Q->head->next->priority = arr[1];
    Q->head->next->next = (QueueNode*) malloc(sizeof(QueueNode));
    Q->head->next->next->T = &arr[2];  // 30
    Q->head->next->next->priority = arr[2];
    printf("First node (head): %p, priority %ld\n", Q->head, Q->head->priority);
    printf("Second node: %p, priority %ld\n", Q->head->next, Q->head->next->priority);
    printf("Third node: %p, priority %ld\n", Q->head->next->next, Q->head->next->next->priority);
    printf("Is queue empty? %d\n", is_queue_empty(Q));

    printf("\nTests on Qtail\n");
    QueueNode *t = Qtail(Q);
    printf("TAIL: %p, priority %ld\n", t, t->priority);

    printf("\nTests on extract_min\n");
    printf("The head is: ");
    int_printer(Q->head->T);
    printf("\nThe min is: ");
    int_printer(extract_min(Q)->T);
    printf("\nFirst node (head): %p, priority %ld\n", Q->head, Q->head->priority);
    printf("Second node: %p, priority %ld\n", Q->head->next, Q->head->next->priority);
    printf("Third node: %p", Q->head->next->next);

    printf("\n\nTests on decrease_key\n");
    printf("First node (head): %p, priority %ld\n", Q->head, Q->head->priority);
    printf("Second node: %p, priority %ld\n", Q->head->next, Q->head->next->priority);
    printf("Decrease key: node %p \n", decrease_key(Q, Q->head->next, 5));
    printf("First node (head): %p, priority %ld\n", Q->head, Q->head->priority);
    printf("Second node: %p, priority %ld\n", Q->head->next, Q->head->next->priority);

    arr[0] = 2; arr[1] = 6; arr[2] = 10; arr[3] = 30; arr[4] = 40;
    PriorityQueue* Q1 = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    Q1->head = NULL;
    Q1->elem_size = sizeof(int);
    Q1->head = (QueueNode*) malloc(sizeof(QueueNode));
    Q1->head->T = &arr[0];  // 10
    Q1->head->priority = arr[0];
    Q1->head->next = (QueueNode*) malloc(sizeof(QueueNode));
    Q1->head->next->T = &arr[1];  // 20
    Q1->head->next->priority = arr[1];
    Q1->head->next->next = (QueueNode*) malloc(sizeof(QueueNode));
    Q1->head->next->next->T = &arr[2];  // 30
    Q1->head->next->next->priority = arr[2];
    Q1->head->next->next->next = (QueueNode*) malloc(sizeof(QueueNode));
    Q1->head->next->next->next->T = &arr[3];  // 40
    Q1->head->next->next->next->priority = arr[3];
    Q1->head->next->next->next->next = (QueueNode*) malloc(sizeof(QueueNode));
    Q1->head->next->next->next->next->T = &arr[4];  // 50
    Q1->head->next->next->next->next->priority = arr[4];
    Q1->head->next->next->next->next->next = NULL;
    
    printf("Another test on decrease_key:\nBefore:\n");
    QueueNode *tmp = Q1->head;
    int o = 1;
    while(tmp && tmp->next){
        printf("Node %d: %p, priority %ld\n", o, tmp, tmp->priority);
        ++o;
        tmp = tmp->next;
    }
    printf("Node %d: %p, priority %ld\n", o, tmp, tmp->priority);
    decrease_key(Q1, Q1->head->next->next, 5);
    printf("After:\n");
    //printf("First node (head): %p, priority %ld\n", Q1->head, Q1->head->priority);
    //printf("Second node: %p, priority %ld\n", Q1->head->next, Q1->head->next->priority);
    //printf("Third node: %p, priority %ld\n", Q1->head->next->next, Q1->head->next->next->priority);
    //printf("Fourth node: %p, priority %ld\n", Q1->head->next->next->next, Q1->head->next->next->next->priority);
    o = 0;
    tmp = Q1->head;
    while(tmp && tmp->next){
        printf("Node %d: %p, priority %ld\n", o, tmp, tmp->priority);
        ++o;
        tmp = tmp->next;
    }
    printf("Node %d: %p, priority %ld\n", o, tmp, tmp->priority);

    printf("\n\nTests on insert_value\n");
    PriorityQueue* Q2 = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    Q2->head = NULL;
    Q2->elem_size = sizeof(float);
    for (i=0; i<=4; ++i)
       insert_value(Q2, &arr2[i], arr2[i]); 

    printf("\n\nTests on print_pqueue\n");
    print_pqueue(Q2, float_printer);

    return 0;
}
