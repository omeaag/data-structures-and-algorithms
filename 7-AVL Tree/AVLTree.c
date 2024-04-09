#include <stdio.h>
#include <stdlib.h>

struct n{
    int data;
    struct n *sag;
    struct n *sol;
};
typedef struct n AVLnode;

int max(AVLnode * node){
    if(node -> sag){
        return max(node -> sag);
    }
    return node -> data;
}

int min(AVLnode * node){
    if (node -> sol)
    {
        return min(node ->sol);
    }
    return node -> data;
}

AVLnode * ekle(AVLnode * node,int x ){
    if(node == NULL){
        AVLnode * t = (AVLnode *) malloc(sizeof(AVLnode));
        t->data = x;
        t->sol = NULL;
        t->sag = NULL;
        return t;
    }

    if (node->data < x)
    {
        node->sag = ekle(node->sag,x);
        return node;
    }
    else if(node->data > x)
    {
        node->sol = ekle(node->sol,x);
        return node;
    }

    return node;
}

AVLnode * sil(AVLnode * node, int x)
{
    if(node -> data == x){
        if(node -> sol == NULL && node -> sag == NULL)
            return NULL;
        if(node -> sag != NULL){
            node -> data = min(node->sag);
            node -> sag = sil(node->sag, min(node->sag));
            return node;
        }
        node ->data = max(node->sol);
        node -> sol = sil(node->sol, max(node->sol));
        return node;
    }

    else if(node->data < x){
        node -> sag = sil(node->sag, x);
        return node;
    }

    else if(node->data > x){
       node->sol = sil(node->sol, x);
       return node;
    }
    
}

int yukseklik(AVLnode * node)
{
    if (node != NULL)
    {
        int left = yukseklik(node->sol);
        int right = yukseklik(node->sag);

        if(right >= left)
            return 1 + right;

        return 1 + left;
    }
    else return -1;
}


//daha sonra avl dengeleme
void bastir(AVLnode * node)
{
    if (node==NULL)
    {
        return;
    }
    
    bastir(node->sol);

    printf("%d -> ", node->data);

    bastir(node->sag);
}

int main(){
    AVLnode * root = NULL;
    root = ekle(root,50);
    root = ekle(root,10);
    root = ekle(root,55);
    root = ekle(root,60);
    root = ekle(root,5);
    root = ekle(root,12);
    root = ekle(root,4);
    root = ekle(root,6);
    root = ekle(root,11);
    root = ekle(root,15);
    root = ekle(root,20);
    root = ekle(root,25);
    // bastir(root);
    // printf("\n");
    // printf("max -> %d", max(root));
    // printf("\n");
    // printf("min -> %d", min(root));
    // // root = sil(root,10);
    // // bastir(root);
    // printf("\n");
    // root = sil(root,10);
    // bastir(root);
    // printf("\n");
    // root = sil(root,50);
    // bastir(root);   
    // printf("\n");
    // root = sil(root,4);
    // bastir(root); 
    // printf("\n");
    // root = sil(root,60);
    // bastir(root); 
    printf("%d ", yukseklik(root));
}