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
  newNode->T = malloc(sizeof(value));
  newNode->next = NULL; // not granted that a newly created pointer is NULL
  // Copy contents of new_data to newly allocated memory. 
  // Assumption: char takes 1 byte. 
  for (int i = 0; i < sizeof(value); i++)
    *(char *)(newNode->T + i) = *(char *)(value + i);
  // Change tail pointer as new node is added at the end
  // We have to check if we have a NULL head (the list is empty), because in this case we have head = tail = newNode.
  if (head == NULL) {
    return newNode;
  }
  tail(head)->next = newNode;
  return head;
}

void push_back_void(ListNode** head, const void* value)
{
  // Allocate memory for the new node
  ListNode* newNode = (ListNode*) malloc(sizeof(ListNode));
  newNode->T = malloc(sizeof(value));
  newNode->next = NULL; // not granted that a newly created pointer is NULL
  // Copy contents of new_data to newly allocated memory. 
  // Assumption: char takes 1 byte. 
  for (int i = 0; i < sizeof(value); i++)
    *(char *)(newNode->T + i) = *(char *)(value + i);
  // Change tail pointer as new node is added at the end
  // We have to check if we have a NULL head (the list is empty), because in this case we have head = tail = newNode.
  if (*head == NULL) {
    *head = newNode;
    return;
  }
  tail(*head)->next = newNode;
  return;
}

void printList(const ListNode* head, void (*key_printer)(const void *value))
{
  printf("Content of the list: ");
  ListNode* tmp = (ListNode*) head;
  while (tmp){
    key_printer(tmp->T);
    tmp = tmp->next;
  }
  printf("\n");

  return;
}

void Ldestructor(ListNode** head)
{
  if (*head == NULL) {
    return;
  }
  ListNode* tmp;
  while(*head != NULL){
    free((*head)->T);
    tmp = *head;
    *head = (*head)->next;
    free(tmp);
  }

  return;
}
