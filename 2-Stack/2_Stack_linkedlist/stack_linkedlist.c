#include <stdio.h>
#include <stdlib.h>
#include "stack_linkedlist.h"

stack * tanim(){
    stack * s = (stack *)malloc(sizeof(stack));
    s -> r = NULL;
    s -> boyut = 0;
}

int pop(stack * s){
    if(s->boyut == 0 || s -> r == NULL)
    {
        printf("dizi bos");
        return -1;
    }

    int i;
    if(s -> r -> next == NULL){
        node * temp = s -> r;
        i = s->r->x;
        s->r = NULL;
        free(temp);
        s->boyut -= 1;
        return i; 
    }

    node * iter = s ->r;
    node * temp;
    
    while (iter ->next ->next != NULL)
    {
        iter = iter ->next;
    }
    temp = iter ->next;
    i = temp->x;
    iter ->next = NULL;
    free(temp);
    s->boyut -= 1;
    return i;
    
}

node * push(int a, stack * s){
    if(s->boyut == 0 || s -> r == NULL){
        s -> r = (node *) malloc(sizeof(node));
        s-> r -> x = a;
        s -> r -> next = NULL;
        s->boyut += 1;

        return s ->r;
    }

    node * iter = s -> r;
    while (iter -> next != NULL)
    {
        iter = iter -> next;
    }
    iter -> next = (node *) malloc(sizeof(node));
    iter -> next ->next = NULL;
    iter -> next -> x = a;
    s -> boyut += 1;
    return s->r;
}

int peek(stack * s){

    if(s ->boyut == 0 || s ->r == NULL){
        printf("dizi bos");
        return -1;
    }

    node * iter = s -> r;
    while (iter ->next != NULL)
    {
        iter = iter -> next;
    }
    return iter ->x;
    
}

void bastir(stack * s){
    if(s ->boyut == 0 || s ->r == NULL){
        printf("dizi bos");
    }
    node * iter = s -> r;
    while (iter != NULL)
    {
        printf("%d ", iter ->x);
        iter = iter -> next;
    }
    printf("\n");
}

