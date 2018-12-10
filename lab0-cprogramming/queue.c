/* 
 * Code for basic C skills diagnostic.
 * Developed for courses 15-213/18-213/15-513 by R. E. Bryant, 2017
 */

/*
 * This program implements a queue supporting both FIFO and LIFO
 * operations.
 *
 * It uses a singly-linked list to represent the set of queue elements
 */

#include <stdlib.h>
#include <stdio.h>

// #include "harness.h"
#include "queue.h"

/*
  Create empty queue.
  Return NULL if could not allocate space.
*/
queue_t *q_new()
{
    /* Remember to handle the case if malloc returned NULL */
    queue_t *queue = (queue_t*)malloc(sizeof(queue_t)); 
    if (queue == NULL) return NULL;
    
    queue->head = NULL;
    queue->tail = NULL;
    queue->q_size = 0;
    return queue;
}

/* Free all storage used by queue */
void q_free(queue_t *q)
{
    /* Remember to free the queue structue and list elements */
    if (q == NULL) return; 
    list_ele_t *temp_elem, *curr_elem = q->head;

    // Free q's elems
    while(curr_elem != NULL)
    {
        temp_elem = curr_elem;
        curr_elem = curr_elem->next;
        free(temp_elem);
    }

    // Free q
    q->head = NULL;
    q->tail = NULL;
    q->q_size = 0;
    free(q);
    q = NULL;
}

/*
  Attempt to insert element at head of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_head(queue_t *q, int v)
{
    /* What should you do if the q is NULL? */
    /* What if malloc returned NULL? */
    if (q == NULL) return false;

    list_ele_t *elem = (list_ele_t*)malloc(sizeof(list_ele_t));
    if (elem == NULL) return false;
    elem->value = v;
    elem->next = q->head;

    q->head = elem;
    if (q->q_size == 0) q->tail = elem;
    q->q_size += 1;

    return true;
}


/*
  Attempt to insert element at tail of queue.
  Return true if successful.
  Return false if q is NULL or could not allocate space.
 */
bool q_insert_tail(queue_t *q, int v)
{
    /* Remember: It should operate in O(1) time */
    if (q == NULL) return false;

    list_ele_t *elem = (list_ele_t*)malloc(sizeof(list_ele_t));
    if (elem == NULL) return false;
    elem->value = v;
    elem->next = NULL;

    
    if (q->q_size == 0)
    {
        q->head = elem;
    } else {
        q->tail->next = elem;
    }   
    q->tail = elem;
    q->q_size += 1;

    return true;
}

/*
  Attempt to remove element from head of queue.
  Return true if successful.
  Return false if queue is NULL or empty.
  If vp non-NULL and element removed, store removed value at *vp.
  Any unused storage should be freed
*/
bool q_remove_head(queue_t *q, int *vp)
{
    if (q == NULL || q->q_size == 0 || q->head == NULL) return false;

    list_ele_t *elem = q->head;
    q->head = elem->next; 
    if (vp != NULL) *vp = elem->value;
    
    elem->next = NULL;
    elem = NULL;
    free(elem);
    q->q_size += -1;
    return true;
}

/*
  Return number of elements in queue.
  Return 0 if q is NULL or empty
 */
int q_size(queue_t *q)
{
    /* Remember: It should operate in O(1) time */
    if (q == NULL || q->q_size == 0 ) return false;
    return q->q_size;
}

/*
  Reverse elements in queue.
  Your implementation must not allocate or free any elements (e.g., by
  calling q_insert_head or q_remove_head).  Instead, it should modify
  the pointers in the existing data structure.
 */
void q_reverse(queue_t *q)
{
    if (q == NULL || q->q_size == 0 || q->q_size == 1 ) return;

    list_ele_t *preserve_head = q->head;
    list_ele_t *preserve_tail = q->tail;

    list_ele_t *prev_elem = NULL;           // a
    list_ele_t *curr_elem = q->head;        // b
    list_ele_t *next_elem = curr_elem;      // c, set not NULL initially to enter while loop

    while (next_elem != NULL)
    {
        next_elem = curr_elem->next;    // c=b->next
        curr_elem->next = prev_elem;    // b->next=a
        prev_elem = curr_elem;          // a=b
        curr_elem = next_elem;
    }

    q->head = preserve_tail;
    q->tail = preserve_head;
}
