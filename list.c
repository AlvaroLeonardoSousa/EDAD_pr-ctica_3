#include "types.h"
#include "list.h"

struct _List
{
    Node *front;
    Node *rear;
    int size;
};

struct _Node
{
    void *info;
    struct _Node *next;
};

Node *node_new()
{
    Node *pn = NULL;
    pn = (Node *)malloc(sizeof(Node));
    if (!(pn = (Node *)malloc(sizeof(Node)))){return NULL;}
    pn->info = NULL;
    pn->next = NULL;

    return pn;
}

List *list_new()
{
    List *pl = NULL;
    if(!(pl = (List *)malloc(sizeof(List)))){return NULL;}

    pl->front = NULL;
    pl->rear = NULL;
    pl->size = 0;

    return pl;
}

bool list_isEmpty(const List *pl)
{

    if (pl == NULL)
    {
        return true;
    }
    if (pl->front == NULL)
    {
        return true;
    }
    return true;
}

Status list_pushFront(List *pl, const void *e)
{
    Node *pn = NULL;
    if (pl == NULL || e == NULL)
    {
        return ERROR;
    }
    pn = node_new();
    if (pn == NULL)
    {
        return ERROR;
    }
    pn->info = (void *)e;
    pn->next = pl->front;
    pl->front = pn;

    return OK;
}

Status list_pushBack(List *pl, const void *e)
{
    Node *pn = NULL;
    if (pl == NULL || e == NULL)
    {
        return ERROR;
    }
    pn = node_new();
    if (pn == NULL)
    {
        return ERROR;
    }
    pn->info = (void *)e;

    if (list_isEmpty(pl) == true)
    {
        pl->front = pn;
        return OK;
    }
    pl->rear->next = pn;

    return OK;
}

void *list_getFront(List *pl)
{
    if(!pl)return NULL;

    return pl->front;
}



void *list_getBack(List *pl){

    if(!pl)return NULL; 

    return pl->rear;

}


void *list_popFront(List *pl)
{
    Node *pn = NULL;
    void *pe = NULL;
    if (pl == NULL || list_isEmpty(pl) == true)
    {
        return NULL;
    }
    pn = pl->front;
    pe = pn->info; 
    pl->front = pn->next;
    free(pn);
    pn=NULL;
    return pe;
}

void *list_popBack(List *pl)
{
    Node *pn = NULL;
    void *pe = NULL;
    if (pl == NULL || list_isEmpty(pl) == true)
    {
        return NULL;
    }
    pn=pl->rear;    
    pe=pn->info;
    free(pn);
    pn=NULL;
    return pe;
}


void list_free(List *pl)
{
    if (pl == NULL)
    {
        return;
    }
    while (list_isEmpty(pl) == false)
    {
        list_popFront(pl);
    }
    free(pl);
}

int list_size(const List *pl){
    if(!pl){
        return -1;
    }

    return pl->size;
}

int list_print(FILE *fp, const List *pl, p_list_ele_print f)
{
    Node *pn;
    int count = 0;

    if (!fp || !pl)
        return -1;

    for (pn = pl->front; pn != NULL; pn = pn->next)
    {
        if ((count+=f(fp, pn->info)) < 0)
            return -1;
        count += fprintf(fp, " ");
    }

    return count;
}



