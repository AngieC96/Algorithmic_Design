#include "List.h"

ListNode* tail(List* l)
{
  ListNode* tmp = l->head;
  while (tmp && tmp->next)
    tmp = tmp->next;

  return tmp;
}

const ListNode* push_back(List* l, const void* value)
{
  // Allocate memory for the new node
  ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
  newNode->T = malloc(l->elem_size);
  newNode->next = NULL; // not granted that a newly created pointer is NULL
  // Copy contents of new_data to newly allocated memory. 
  // Assumption: char takes 1 byte. 
  int i; 
  for (i=0; i<l->elem_size; i++)
    *(char *)(newNode->T + i) = *(char *)(value + i);
  // Change tail pointer as new node is added at the end
  // We have to check if we have a NULL head (the list is empty), because in this case we have head = tail = newNode.
  if (l->head == NULL) {
    l->head = newNode;
  } else {
    printf("\nIn push_back\nFirst node (head): %p, value %d\n", l->head, (const int *)l->head->T);
    printf("Second node: %p\n", l->head->next);
    printf("Third node: %p\n", l->head->next);
    tail(l)->next = newNode;
  }

  return newNode;
}

void printList(const List* l, void (*key_printer)(const void *value))
{
  printf("Content of the list: ");
  ListNode* tmp = l->head;
  while (tmp && tmp->next){
    if (tmp == l->head) key_printer(tmp->T);
    tmp = tmp->next;
    key_printer(tmp->T);
  }
  printf("\n");

  return;
}

void Ldestructor(List* l)
{
  printf("\nIn Ldestructor\n");
  ListNode* headL = l->head;
  printf("head: %p\n", headL);
  while(headL){
    free(headL->T);
    headL = headL->next;
    printf("head: %p\n", headL);
  }

  printf("free l\n");
  free(l);
}
