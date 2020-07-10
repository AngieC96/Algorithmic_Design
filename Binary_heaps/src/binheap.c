#include <binheap.h>
#include <stdio.h>
#include <string.h>

#define PARENT(node) ((node-1)/2)
#define LEFT_CHILD(node) (2*(node) + 1)
#define RIGHT_CHILD(node) (2*(node + 1))

/* A node is valid whenever the number of elements in the heap is greater than the node itself*/
#define VALID_NODE(H, node) ((H)->num_of_elem>(node))

/* Returns the address of a pointer to the the value stored in the node `node` */
/* Returns a pointer to that node inside the data structure */
// It is like A[i] that it is not possible since we are using a pointer to void
#define ADDR(H, node) ((H)->A+(node)*(H)->key_size)
/* Returns the index of the node's address given */
#define INDEX_OF(H, addr) (((addr)-((H)->A))/((H)->key_size))



int is_heap_empty(const binheap_type *H)
{
    return H->num_of_elem==0;
}

const void *min_value(const binheap_type *H)
{
    if(is_heap_empty(H))
        return NULL; // To handle the case of an empty heap when I cannot return any minumim value

    // The minimum is stored in the root a.k.a. A[0]
    return ADDR(H, 0);
}

void swap_keys(binheap_type *H, unsigned int n_a, unsigned int n_b)
{
    void *p_a = ADDR(H, n_a);
    void *p_b = ADDR(H, n_b);
    void *tmp = malloc(H->key_size);

    memcpy(tmp, p_a, H->key_size);
    memcpy(p_a, p_b, H->key_size);
    memcpy(p_b, tmp, H->key_size);

    free(tmp);
}

void heapify(binheap_type *H, unsigned int node)
{
    unsigned int dst_node = node; // The node containing the minimum among the node and its children
    unsigned int child;

    do {
        node = dst_node;

        // Find the minimoum among node and its children
        child = RIGHT_CHILD(node);

        if(VALID_NODE(H, child) && H->leq(ADDR(H, child), ADDR(H, dst_node))){
            // If I am in a leaf VALID_NODE is false! Because a leaf doesn't have a right child
            dst_node = child;
        }

        child = LEFT_CHILD(node);

        if(VALID_NODE(H, child) && H->leq(ADDR(H, child), ADDR(H, dst_node))){
            dst_node = child;
        }

        // If the minimum is not in node swap the keys
        if(dst_node != node){
            swap_keys(H, dst_node, node);
        }
    } while(dst_node != node);
}

const void *extract_min(binheap_type *H)
{
    if(is_heap_empty(H))
        return NULL;

    // Swapping the keys among the root and the right-most leaf
    // of the last level (A[num_of_elements-1])
    swap_keys(H, 0, H->num_of_elem-1);

    // Deleting the right-most leaf of the last level (A[num_of_elem-1])
    H->num_of_elem--;

    heapify(H, 0);

    return ADDR(H, H->num_of_elem+1);
}

const void *find_the_max(void *A, 
                         const unsigned int num_of_elem,
                         const size_t key_size, 
                         total_order_type leq)
{
    if(num_of_elem==0){
        return NULL;
    }

    const void *max_value = A; // I take the first value in A
    // I go through all the elements in A
    for(const void *addr = A+key_size; addr != A + num_of_elem*key_size; addr += key_size){
        // If addr > max_value
        if(!leq(addr, max_value)){
            max_value = addr;
        }
    }

    return max_value;
}

binheap_type *build_heap(void *A, 
                         const unsigned int num_of_elem,
                         const unsigned int max_size,  
                         const size_t key_size, 
                         total_order_type leq)
{
    binheap_type *H = (binheap_type *) malloc(sizeof(binheap_type));

    H->A = A;
    H->num_of_elem = num_of_elem;
    H->max_size = max_size;
    H->key_size = key_size;
    H->leq = leq;
    H->max_order_value = malloc(key_size); // It's a void value so we're NOT type-casting the malloc!

    if(num_of_elem==0){
        return H;
    }

    // Get the maximum among A[0, ..., num_of_elem-1] and store it in max_order_value
    const void *value = find_the_max(A, num_of_elem, key_size, leq);
    memcpy(H->max_order_value, value, key_size);

    // Fix the heap property from the second last level to the root
    for(unsigned int i = num_of_elem/2; i > 0; --i){
        heapify(H, i);
    }
    heapify(H, 0);

    return H;
}

void delete_heap(binheap_type *H)
{
    free(H->max_order_value);
    free(H);
}

const void *decrease_key(binheap_type *H, void *node, const void *value)
{
    unsigned int node_idx = INDEX_OF(H, node);

    // If node doesn't belong to H or *value >=*node retunr NULL
    if(!VALID_NODE(H, node_idx) || !(H->leq(value, node))){
        return NULL;
    }

    memcpy(node, value, H->key_size);

    unsigned int parent_idx = PARENT(node_idx);
    void *parent = ADDR(H, parent_idx);

    // While node != root and *parent> *node swap parent and node keys
    while((node_idx != 0) && (!H->leq(parent, node))) {
        swap_keys(H, parent_idx, node_idx);

        // Focus on the node's parent
        node = parent;
        node_idx = parent_idx;

        parent_idx = PARENT(node_idx);
        parent = ADDR(H, parent_idx);
    }

    return node;
}

const void *insert_value(binheap_type *H, const void *value)
{
    // If the heap is already full
    if(H->max_size == H->num_of_elem){
        return NULL;
    }

    // If the new value > *max_order_value
    if(H->num_of_elem == 0 || !H->leq(value, H->max_order_value)){
        memcpy(H->max_order_value, value, H->key_size);
    }

    // Get the position of the new node
    void *new_node_addr = ADDR(H, H->num_of_elem); // Address in the array A of the new node
    memcpy(new_node_addr, H->max_order_value, H->key_size);

    // In crease the size of the neap by 1
    H->num_of_elem++;

    // Decrease the key of the new node
    return decrease_key(H, new_node_addr, value);
}

void print_heap(const binheap_type *H, 
                void (*key_printer)(const void *value))
{
    unsigned int next_level_node = 1; // To store the index of the left-most node of the next level

    for(unsigned int node = 0; node < H->num_of_elem; ++node){ // The node I am dealing with
        if(node == next_level_node){
            printf("\n");
            next_level_node = LEFT_CHILD(node);
        } else {
            printf("\t");
        }

        key_printer(ADDR(H, node));
    }

    printf("\n");
}
