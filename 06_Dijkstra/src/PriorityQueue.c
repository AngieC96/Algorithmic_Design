#include <PriorityQueue.h>

PriorityQueue* build_queue(size_t elem_size)
{
    PriorityQueue* Q = (PriorityQueue*) malloc(sizeof(PriorityQueue));
    Q->head = NULL;
    Q->elem_size = elem_size;
}

int is_queue_empty(const PriorityQueue *Q)
{
    return Q->head == NULL;
}

QueueNode* Qtail(PriorityQueue* Q)
{
    QueueNode* tmp = Q->head;
    while (tmp && tmp->next)
        tmp = tmp->next;

    return tmp;
}

const QueueNode* extract_min_pq(PriorityQueue *Q)
{
    if(is_queue_empty(Q))
        return NULL;

    // The minimum is stored in the first element of the queue, since it is ordered
    // So remove the head and subsitute it with the second element
    QueueNode* tmp = Q->head;
    Q->head = tmp->next;
    
    return tmp;
}

const QueueNode* decrease_key_pq(PriorityQueue* Q, QueueNode* node, const size_t value)
{
    if(is_queue_empty(Q))
        return NULL;
    
    // We decrease the priority of the node
    QueueNode *tmp = Q->head, *tmp2, *smaller_node, *prev_node;
    while (tmp && tmp->next && tmp != node){
        if (tmp->priority < value){
            smaller_node = tmp;  // I save the node that should be just before the node with the decreased key in the ordered list
        }
        prev_node = tmp;  // I keep track of the node before the one to decrease
        tmp = tmp->next;
    }

    // We change the priority of the node
    tmp->priority = value;
    // Now we insert the node with the new priority in the right place so the queue is sorted again
    tmp2 = tmp->next;
    if(Q->head->priority >= value){
        tmp->next = Q->head;
        Q->head = tmp;
    } else {
        tmp->next = smaller_node->next;
        smaller_node->next = tmp;
    }
    prev_node->next = tmp2;

    return tmp;
}

const void *insert_value_pq(PriorityQueue* Q, const void* value, size_t priority)
{
    // Allocate memory for the new node
    QueueNode* newNode = (QueueNode*) malloc(sizeof(QueueNode));
    newNode->T = malloc(Q->elem_size);
    newNode->priority = priority;
    newNode->next = NULL; // not granted that a newly created pointer is NULL

    // Copy contents of new_data to newly allocated memory. 
    // Assumption: char takes 1 byte. 
    int i; 
    for (i=0; i<Q->elem_size; i++)
        *(char *)(newNode->T + i) = *(char *)(value + i);

    // Change tail pointer as new node is added at the end
    // We have to check if we have a NULL head (the list is empty), because in this case we have head = tail = newNode.
    if (Q->head == NULL) {
        Q->head = newNode;
    } else {
        Qtail(Q)->next = newNode;
    }

    return newNode;
}

void print_pqueue(const PriorityQueue* Q, void (*key_printer)(const void *value))
{
    printf("Content of the queue: ");
    QueueNode* tmp = Q->head;
    while (tmp && tmp->next){
        printf("(");
        key_printer(tmp->T);
        printf("%ld), ", tmp->priority);
        tmp = tmp->next;
    }
    printf("(");
        key_printer(tmp->T);
        printf("%ld)\n", tmp->priority);

    return;
}
