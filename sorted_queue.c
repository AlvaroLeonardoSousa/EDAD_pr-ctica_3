/**
 * @brief This file contains the implementation of the sorted queue
 *
 * @file sorted_queue.c
 * @author A. Leonardo & D. Tabero
 * @version 1
 */

#include "sorted_queue.h"

#include <stdio.h>
#include <stdlib.h>

SortedQueue *squeue_new() {
    SortedQueue *squeue_new = NULL;

    squeue_new = queue_new();

    if (squeue_new == NULL) {
        return NULL;
    }

    return squeue_new;

}

void squeue_free(SortedQueue *q) {
    queue_free(q);
}

bool squeue_isEmpty(const SortedQueue *q) {
    return queue_isEmpty(q);
}

Status squeue_push(SortedQueue *q, void *elem, compare_elem_fn cmp) {
    
    void *aux = NULL;

    if (!q|| !elem) {
        return ERROR;
    }

    while (!queue_isEmpty(q) && cmp(elem, queue_getFront(q)) > 0) {
        aux = queue_pop(q);
        if(queue_push(q, aux) == ERROR) {
            return ERROR;
        }
    }

    if(queue_push(q, elem) == ERROR) {
        return ERROR;
    }

    while (!queue_isEmpty(q) && cmp(elem, queue_getFront(q)) <= 0) {
        aux = queue_pop(q);
        if(queue_push(q, aux) == ERROR) {
            return ERROR;
        }
    }

    return OK;

}

void *squeue_pop(SortedQueue *q) {
    return queue_pop(q);
}

void *squeue_getFront(const SortedQueue *q) {
    return queue_getFront(q);
}

void *squeue_getBack(const SortedQueue *q) {
    return queue_getBack(q);
}

size_t squeue_size(const SortedQueue *q) {
    return queue_size(q);
}

int squeue_print(FILE *fp, const SortedQueue *q, print_elem_fn print_elem) {
    return queue_print(fp, q, print_elem);
}

