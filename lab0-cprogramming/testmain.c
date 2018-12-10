#include <stdio.h>
#include "queue.h"


void print_elem(const list_ele_t *e)
{
    if(e) 
    { 
        printf("[%d]", e->value); 
    } else {
        printf("[NULL]");
    }

    if(e->next)
    {
        printf("->[%d], ", e->next->value);
    } else {
        printf("->[NULL]");
    }   
}

void print_queue(const queue_t *q)
{
    if (q)
    {
        printf("Q --> %d items\n", q->q_size);
        
        if (q->head) {
            printf("head = %d, ", q->head->value);
        } else {
            printf("head = NULL, ");
        }

        if (q->tail) {
            printf("tail = %d\n", q->tail->value);
        } else {
            printf("tail = NULL\n");
        }

        for (list_ele_t *elem = q->head; elem != NULL; elem=elem->next)
        {
            print_elem(elem);
        }
        printf("\n");
    } else {
        printf("NULL queue\n");
    }
}

int main (int argc, char *argv[])
{
    queue_t* q = NULL;
    q = q_new();

    print_queue(q);

    q_insert_head(q, 1);
    q_insert_tail(q, 0);
    q_insert_head(q, 3);
    q_insert_head(q, 2);
    q_insert_tail(q, 5);
    printf("Queue should be: [2]->[3]->[1]->[0]->[5]->NULL\n");
    print_queue(q);

    printf("\nShould have removed 2 from queue\n");
    int a;
    q_remove_head(q, &a);
    print_queue(q);

    printf("\nShould have reversed queue\n");
    q_reverse(q);   
    print_queue(q);

    printf("\nShould have freed queue\n");
    q_free(q);
    printf("Queue = null is %s", q ? "true\n" : "false\n" );

    printf("\nShould be empty q, 1 inserted at head\n");
    q = q_new();
    q_insert_head(q, 1);
    print_queue(q);

    q_free(q);
    printf("\nShould be empty q, 10 inserted at tail\n");
    q = q_new();
    q_insert_tail(q, 10);
    print_queue(q);
}