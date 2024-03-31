#include <stdio.h>
#include <stdlib.h>
#include <wingdi.h>

struct n {
    int x;
    struct n * next;
};

typedef struct n node;

void print_list(node * r){

    while( r != NULL){

        printf("%d ", r -> x);

        r = r -> next;
    }
}

void ekle_list(node * r, int x){

    while( r -> next != NULL){
        r = r -> next;
    }

    r -> next = (node *) malloc(sizeof(node));
    r = r -> next;
    r -> x = x;
    r -> next = NULL;


}

int main(){

    node * root = (node *) malloc(sizeof(node));

    root -> x = 0;
    root -> next = NULL;

    node * iter;
    iter = root;

    for (int i = 1; i < 10 ; i++)
    {
        ekle_list(root, i*6);

    }

   print_list(root);
    
}