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

node * sil(node * agac, int x){
    if(agac == NULL)
        return NULL;

    if(agac->data == x){
        if(agac->sol==NULL && agac->sag==NULL)
            return NULL;
        if(agac->sag != NULL){
            agac->data = min(agac->sag);
            agac-> sag = sil(agac->sag, min(agac->sag));
            return agac;
        }

        agac ->data = max(agac->sol);
        agac->sol = sil(agac->sol, max(agac->sol));
        return agac;

    }
    if(agac->data < x){
        agac->sag = sil(agac->sag,x);
        return agac;
    }

    agac->sol = sil(agac->sol, x);
    return agac;
}

int main(){
    node * agac = NULL;
    agac = ekle(agac, 16);
    agac = ekle(agac, 9);
    agac = ekle(agac, 23);
    agac = ekle(agac, 5);
    agac = ekle(agac, 10);
    agac = ekle(agac, 1);
    agac = ekle(agac, 6);
    agac = ekle(agac, 12);
    agac = ekle(agac, 13);
    agac = ekle(agac, 19);
    agac = ekle(agac, 27);
    agac = ekle(agac, 24);

    dolas(agac);
    printf("\n%d ", bul(agac,10));
    printf("\n%d ", bul(agac,45));

    printf("\n%d ", min(agac));
    printf("\n%d ", max(agac));
    printf("\n");
    agac = sil(agac,16);
    dolas(agac);
}