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

        printf("%d ", r->x);

        r = r->next;
    }
}

int main(){

    node * root = (node *) malloc(sizeof(node));

    root -> x = 0;
    root -> next = (node *) malloc(sizeof(node)); 
    root -> next -> x = 5;
    root -> next -> next = (node *) malloc(sizeof(node));
    root -> next -> next -> x = 10;
    root -> next -> next -> next = NULL;

    node * iter;
    iter = root;
    
    //LİSTENİN SONUNA GİDİP ELEMAN EKLEME
    while(iter->next != NULL){ //iter null olmayana kadar çalış

        // printf("%d", iter -> x);

        iter = iter -> next;
    }
    

    for (int i = 3; i < 8 ; i++)
    {
        iter -> next = (node *) malloc(sizeof(node));
        iter = iter -> next;
        iter -> x = i * 5;
        iter -> next = NULL;

    }

   print_list(root);
    
}