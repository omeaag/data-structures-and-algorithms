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

node * ekle_sirali(node * r, int x){

    if(r == NULL){ //listenin boş olma durumu
        r = (node *) malloc(sizeof(node));
        r -> next = NULL;
        r -> x = x;
        return r;
    }

    if(r -> x > x){ //eklenen elemanın root değerinden küçük olması - root değişiyor
        node * temp = (node*) malloc(sizeof(node));
        temp -> x = x;
        temp -> next = r;
        return temp;
    }
   
    node * iter = r;

    while (iter->next != NULL && iter->next->x < x) 
    {
        iter = iter ->next;
    }
    //iter'in nexti NULL değilse ve iter'in nextinin x değeri eklenen elemanın x değerinden küçük olması durumunda çalıştır.
    //yani iter'in nextinin NULL olması sonuncu elemana gelindiğini gösterir. bu yüzden 
    // iter = iter -> next dersek iter NULL değerini gösterir.
    // eğer iter'in nextinin x değeri eklenen değerden büyükse yine iter = iter -> next dememeliyiz çünkü eklenecek değerimiz iter ve next değeri arasına gelineceğini gösterir.
    
    // örneğin listemizde 10i -> 20 -> 30 -> 40 -> 50 değerleri var. eklenecek değerimiz 35 olsun. while döngüsünü bu örnek üzerinde kafanda çalıştırırsan anlarsın  

    node * temp = (node *) malloc(sizeof(node));
    temp -> x = x;
    temp -> next = iter->next;
    iter -> next = temp;

    return r;
}

int main(){

    node * root = NULL;

    root = ekle_sirali(root,40);
    root = ekle_sirali(root,25);
    root = ekle_sirali(root,80);
    root = ekle_sirali(root,75);
    root = ekle_sirali(root,15);
    root = ekle_sirali(root,60);
    root = ekle_sirali(root,100);
    root = ekle_sirali(root,95);
    root = ekle_sirali(root,12);
    root = ekle_sirali(root,35);
    root = ekle_sirali(root,55);
    root = ekle_sirali(root,85);
    root = ekle_sirali(root,222);
    root = ekle_sirali(root,10);
    
   print_list(root);
     
}