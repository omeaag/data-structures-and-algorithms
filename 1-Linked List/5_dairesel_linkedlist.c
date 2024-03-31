#include <stdio.h>
#include <stdlib.h>
#include <wingdi.h>

struct n {
    int x;
    struct n * next;
};

typedef struct n node;

void print_list(node * r){
    node * iter = r;

    printf("%d ", iter -> x);
    iter = iter -> next; // iter ile root ilk başta eşit olduğundan döngü hiç çalışmayacaktır. bu yüzden döngüden önce iter'i bir kere öteledik.

    while( iter != r){

        printf("%d ", iter -> x);
        iter = iter -> next;
    }
    printf("\n");
}

void ekle_list(node * r, int x){
    node * iter = r;

    while( iter -> next != r){
        iter = iter -> next;
    }

    iter -> next = (node *) malloc(sizeof(node));
    iter ->next-> x = x;
    iter -> next -> next = r;

}

node * ekle_sirali(node * r, int x){

    if(r == NULL){ //listenin boş olma durumu
        r = (node *) malloc(sizeof(node));
        r -> x = x;
        r -> next = r;
        return r;
    }

    if(r -> x > x){ //eklenen elemanın root değerinden küçük olması - root değişiyor
        node * temp = (node*) malloc(sizeof(node));

        temp -> x = x;
        temp -> next = r;

        node * iter = r;
        while(iter->next != r){
            iter = iter->next;
        }
        iter ->next = temp;

        return temp;
    }
    

    //araya veya sona ekleme yapma

    node * iter = r;

    while (iter-> next != r && iter->next->x < x) 
    {
        iter = iter ->next;
    }
    
    node * temp = (node *) malloc(sizeof(node));
    temp -> x = x;
    temp -> next = iter -> next;
    iter -> next = temp;

    return r;
}

node * sil(node * r, int x){
    node * temp;
    node * iter = r;

    if(r -> x == x){ //silinecek elemanın root elemanı olma durumu

        while (iter -> next != r)
        {
            iter = iter -> next;
        }

        iter -> next = r -> next;

        free(r);

        return iter -> next;
    }

    while(iter -> next != r && iter -> next -> x != x){// "!=" -> "farklı iken" 
        iter = iter -> next;
    }

    if(iter-> next == r){
        printf("sayi bulunamadi");
        return r;
    }

    temp = iter -> next;
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

     
}