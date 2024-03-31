#include <stdio.h>
#include <stdlib.h>
#include <wingdi.h>

struct n {
    int x;
    struct n * next;
};

typedef struct n node;

int main(){

    node * root = (node *) malloc(sizeof(node));

    root -> x = 0;
    root -> next = (node *) malloc(sizeof(node)); 
    root -> next -> x = 5;
    root -> next -> next = (node *) malloc(sizeof(node));
    root -> next -> next -> x = 10;

    node * iter;
    iter = root;
    
    printf("%d", iter -> x);
    iter = iter -> next;
    printf("%d", iter -> x);
    iter = iter -> next;
    printf("%d", iter -> x);
}