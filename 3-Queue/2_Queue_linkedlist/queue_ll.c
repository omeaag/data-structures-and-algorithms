#include <stdio.h>
#include <stdlib.h>
#include "queue_ll.h"

queue * tanim()
{
    queue * q = (queue *)malloc(sizeof(queue));
    q->r = NULL;
    q->boyut = 0;
}


node * deque(queue * q)
{
    if(q->r == NULL)
    {
        printf("dizi bos");
        return q->r;
    }
    node * temp = q->r;
    q->r = q->r->next;
    free(temp);

    return q->r;
}

node * enque(int a, queue * q)
{
    if(q->r == NULL){

        q->r = (node *) malloc(sizeof(node));
        q->r->next = NULL;
        q->r->data = a;
        q->boyut += 1;
        return q->r;

    }

    node * iter = q -> r;
    while (iter -> next != NULL)
    {
        iter = iter -> next;
    }
    
    iter->next = (node *) malloc(sizeof(node));
    
    iter->next->next = NULL;
    
    iter->next->data = a;
    q->boyut += 1;

    return q->r;
}

void bastir(queue *q) 
{
    node* iter = q->r;
    while (iter != NULL)
    {
        printf("%d ", iter->data);
        iter = iter -> next;
    }
    printf("\n");
    
}
