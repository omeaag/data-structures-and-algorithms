#include <stdio.h>
#include <stdlib.h>

struct n {
    int data;
    struct n * sol;
    struct n * sag;
};

typedef struct n node;

node * ekle(node * agac, int x){
    if(agac == NULL) {
        node * root = (node *) malloc(sizeof(node));
        root -> data = x;
        root -> sag = NULL;
        root -> sol = NULL;

        return root;
    }

    if(agac->data < x){
        agac -> sag = ekle(agac ->sag, x); 
        return agac;
    }

    agac ->sol = ekle(agac ->sol, x);
    return agac;
}

int bul(node * agac, int aranan){
    if(agac == NULL)
        return -1;

    if(agac->data == aranan)
        return 1;

    if(bul(agac->sag, aranan) == 1)
        return 1;

    if(bul(agac->sol,aranan) == 1)
        return 1;
}

int max(node * agac){
    while (agac->sag != NULL)
    {
        agac = agac->sag;
    }
    return agac->data;
}

int min(node * agac){
    while (agac->sol != NULL)
    {
        agac = agac->sol;
    }
    return agac->data;
}

void dolas(node * agac){
    if(agac == NULL)
        return;

    dolas(agac ->sol);
    printf("%d ", agac ->data);
    dolas(agac ->sag);
}

int main(){
    node * root = NULL;
    root = ekle(root, 15);
    root = ekle(root, 95);
    root = ekle(root, 25);
    root = ekle(root, 45);
    root = ekle(root, 88);
    root = ekle(root, 102);
    root = ekle(root, 5);
    dolas(root);
    printf("\n%d ", bul(root,10));
    printf("\n%d ", bul(root,45));

    printf("\n%d ", min(root));
    printf("\n%d ", max(root));
}