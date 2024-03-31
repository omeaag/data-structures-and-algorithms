#include <stdio.h>
#include <stdlib.h>
#include "queue_arr.h"

int * dizi = NULL;
int tepe = 0;
int first = 0;
int boyut = 2;

int deque(){
    if (tepe==first || dizi == NULL) 
    {
        printf("\n dizi bos \n ");
        return -1;
    }
    if (tepe - first <= boyut / 4 )
    {
        boyut /= 2;

        int * dizi2 = (int *) malloc((sizeof(int) *boyut));

        for (int i = 0; i < tepe - first; i++)
        {
            dizi2[i] = dizi[i+first];
        }
        free(dizi);

        dizi = dizi2;

        tepe = tepe - first;
        
        first = 0;
        
    }
    
    return dizi[++first];
    
}

void enque(int a){
    if (dizi == NULL)
    {
        dizi = (int *) malloc(sizeof(int)*2);
    }
    if (tepe>= boyut - 1)
    {
        boyut *= 2;

        int * dizi2 = (int *) malloc(sizeof(int)*boyut);
        for (int i = 0; i < tepe-first; i++)
        {
            dizi2[i] = dizi[i+first];
        }
        free(dizi);

        dizi = dizi2; 
        
        tepe = tepe - first;
        
        first = 0;       
    }
    
    dizi[tepe++] = a;
    
}

int bastir(){
    printf("\n");
    printf("dizinin boyutu : %d\n", boyut);
    printf("first : %d\n", first);
    printf("tepe : %d\n", tepe);
    
    for (int i = 0; i < tepe - first; i++)
    {
        printf("%d ", dizi[i+first]);
    }
    printf("\n");
    printf("-----------------------------------------------------------");
    
}
