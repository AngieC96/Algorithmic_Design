#include "List.h"

ListNode* tail(ListNode* head)
{
  while (head && head->next)
    head = head->next;

  return head;
}

ListNode* push_back(ListNode* head, const void* value)
{
  // Allocate memory for the new node
  ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
  //newNode->T = malloc(sizeof(value));
  newNode->T = value; //malloc(sizeof(int));
  newNode->next = NULL; // not granted that a newly created pointer is NULL
  // Copy contents of new_data to newly allocated memory. 
  // Assumption: char takes 1 byte. 
  //for (int i = 0; i < sizeof(value); i++)
  //  *(char *)(newNode->T + i) = *(char *)(value + i);
  // Change tail pointer as new node is added at the end
  // We have to check if we have a NULL head (the list is empty), because in this case we have head = tail = newNode.
  if (head == NULL) {
    return newNode;
  }
  tail(head)->next = newNode;
  return head;
}

void printList(const ListNode* head, void (*key_printer)(const void *value))
{
  printf("Content of the list: ");
  ListNode* tmp = head;
  while (tmp){
    key_printer(tmp->T);
    tmp = tmp->next;
  }
  printf("\n");

  return;
}

//remove_back()
//{}

void Ldestructor(ListNode* head)
{
  // printf("\nIn Ldestructor\n");
  // ListNode* headL = head;
  // printf("head: %p\n", headL);
  // while(headL){
  //   free(headL->T);
  //   headL = headL->next;
  //   free(headL);
  //   printf("head: %p\n", headL);
  // }

  // printf("free l\n");
  // free(head);
}
