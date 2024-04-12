
#include "types.h"
#include "list.h"
#include "queue.h"

struct _Queue
{
    List *pl;
};

Queue *queue_new()
{
    Queue *pq = NULL;
    pq = (Queue *)malloc(sizeof(Queue));
    if (pq == NULL)
    {
        return NULL;
    }
    pq->pl = list_new();
    if (pq->pl == NULL)
    {
        free(pq);
        return NULL;
    }
    return pq;
}

void queue_free(Queue *pq)
{
    if (pq != NULL)
    {
        list_free(pq->pl);
        free(pq);
    }
}

bool queue_isEmpty(const Queue *pq)
{
    if (pq == NULL)
    {
        return true;
    }
    return list_isEmpty(pq->pl);
}

Status queue_push(Queue *pq, const void *e)
{
    if (pq == NULL || e == NULL)
    {
        return ERROR;
    }
    return list_pushBack(pq->pl, e);
}

void *queue_pop(Queue *pq)
{
    if (pq == NULL)
    {
        return NULL;
    }
    return list_popFront(pq->pl);
}

void *queue_getFront(const Queue *pq)
{
    if (pq == NULL)
    {
        return NULL;
    }
    return list_getFront(pq->pl);
}

void *queue_getBack(const Queue *pq){

    if (pq == NULL)
    {
        return NULL;
    }
    return list_getFront(pq->pl);
}

size_t queue_size(const Queue *pq)
{
    if (pq == NULL)
    {
        return 0;
    }
    return sizeof(pq);
}

int queue_print(FILE *fp, const Queue *pq, print_elem_fn print_elem)
{
    if (pq == NULL || fp == NULL || print_elem == NULL)
    {
        return ERROR;
    }
    return list_print(fp, pq->pl, print_elem);
}