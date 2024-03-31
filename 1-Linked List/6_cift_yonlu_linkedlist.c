#include <stdio.h>
#include <stdlib.h>
#include <wingdi.h>

struct n {
    int x;
    struct n * next;
    struct n * prev;
};

typedef struct n node;

void print_list(node * r){
    node * iter = r;

    while( iter != NULL){

        printf("%d ", iter -> x);
        iter = iter -> next;
    }
    printf("\n");
}

node * ekle_sirali(node * r, int x){

    if(r == NULL){ //listenin boş olma durumu
        r = (node *) malloc(sizeof(node));
        r -> x = x;
        r -> next = NULL;
        r -> prev = NULL;

        return r;
    }

    if(r -> x > x){ //eklenen elemanın root değerinden küçük olması - root değişiyor
        node * temp = (node*) malloc(sizeof(node));

        temp -> x = x;
        temp -> next = r;
        temp -> prev = NULL;
        r -> prev = temp;
        
        return temp;
    }
    

    //araya veya sona ekleme yapma

    node * iter = r;

    while (iter -> next != NULL && iter -> next -> x < x) 
    {
        iter = iter -> next;
    }
    
    node * temp = (node *) malloc(sizeof(node));
    temp -> x = x;
    temp -> next = iter -> next;
    temp -> prev = iter;

    if(temp -> next != NULL)
    //sona ekleme işleminde bu işlem yapılmamalıdır, çünkü NULL'ın previ yoktur.
    { 
        temp -> next -> prev = temp;
    }
    
    iter -> next = temp;

    return r;
}

node * sil(node * r, int x){
    node * temp;
    node * iter = r;

    if(r -> x == x){ //silinecek elemanın root elemanı olma durumu

        temp = r;

        r = r -> next;
        r -> prev = NULL;

        free(temp);

        return r;
    }

    while(iter -> next != NULL && iter -> next -> x != x){// "!=" -> "farklı iken" 
        iter = iter -> next;
    }

    if(iter-> next == NULL){
        printf("sayi bulunamadi");
        printf("\n");
        return r;
    }

    temp = iter -> next;

    if(iter -> next -> next != NULL){
        iter -> next -> next -> prev = iter;
    }
    
    iter -> next = iter -> next -> next;

    free(temp);

    return r;
}

int main(){

    node * root = NULL;

    root = ekle_sirali(root,40);
    root = ekle_sirali(root,25);
    root = ekle_sirali(root,222);
    root = ekle_sirali(root,80);
    root = ekle_sirali(root,75);
    root = ekle_sirali(root,60);
    root = ekle_sirali(root,10);
    
    print_list(root);

    root = sil(root,75);

    print_list(root);

    root = sil(root,222);

    print_list(root);

    root = sil(root,333);
    
    print_list(root);

    root = sil(root,10);

    print_list(root);
    
}