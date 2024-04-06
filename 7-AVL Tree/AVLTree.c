#include <stdio.h>
#include <stdlib.h>

struct n{
    int data;
    struct n *sag;
    struct n *sol;
};
typedef struct n AVLnode;

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

AVLnode * sil(AVLnode * node,int x)
{
    if(node -> data == x){
        if(node -> sol == NULL&&node -> sag == NULL)
            return NULL;
        
        
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

//önce max min yazılacak ve silme işlemi halledilcek
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
    root = ekle(root,15);
    root = ekle(root,25);
    root = ekle(root,10);
    root = ekle(root,5);
    root = ekle(root,30);
    bastir(root);
    printf("\n");
    printf("max -> %d", max(root));
    printf("\n");
    printf("min -> %d", min(root));
    // root = sil(root,10);
    // bastir(root);
}