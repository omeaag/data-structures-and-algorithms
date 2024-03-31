#include <stdio.h>
#include <stdlib.h>
#include "stack_arr.h"

stack * tanim(){
    stack * s = (stack *)malloc(sizeof(stack)); //stack tanımı yapılıyor
    //önce malloc ile hafızada stack'i initialize etmemiz gerekiyor. daha sonra atamasını yapmak gerekiyor. stack var olmadan atamasını nasıl yapabiliriz ki?
    //Yığın (stack) türünde bir 's' değişkeni oluştur ve bellekte stack türünde bir alan için bellekten (malloc fonksiyonuyla) yer ayır.
    
    //Kod satırındaki '*' işareti, bir işaretçinin (pointer) kullanıldığını belirtir. Bu durumda, (stack *) ifadesi bir işaretçi tip dönüşümü gerçekleştirir. malloc fonksiyonu, bellekten ayrılan alanın boyutunu byte cinsinden alır. Ancak bu alanın hangi tür veri için kullanılacağını bilmez. Bu nedenle, (stack *) ifadesiyle bu alanın bir yığın (stack) türüne işaret eden bir işaretçi olduğu belirtilir. Yani, malloc(sizeof(stack)) ifadesi bir yığın türünden bellek alanı ayırır ve bu alanın adresini içeren bir işaretçi döndürür. Bu işaretçi daha sonra s değişkenine atanır.

    s->dizi = NULL;
    s->tepe = 0;
    s-> boyut = 2;
    return s;
}

int pop(stack * s){
    if (s->tepe <= 0 || s->dizi == NULL)
    {
        printf("%d\n","dizi bos");
        return -1;
    }
    if (s->tepe == s-> boyut/4)
    {
        int * dizi2= (int*) malloc(sizeof(int)*s->boyut/2);
        for (int i = 0; i < s->tepe; i++)
        {
            dizi2[i] = s->dizi[i];
        }
        free(s->dizi);
        s->dizi = dizi2;

        s -> boyut /= 2;
        
    }
    
    return s->dizi[--s->tepe]; 
    //aslında sonuncu eleman silinmiyor, tepe değeri değişiyor sadece :)
    //çıkarılan elemanın hafızadaki konumu silinmiyor. Stack veri yapısında, elemanlar sıralı bir şekilde bellekte saklanır ve her eleman, stack'e eklenirken en üstteki boş alana yerleştirilir. Eleman çıkarıldığında, o elemanın değeri döndürülür ve bellekteki konumu artık stack tarafından kullanılmadığı için diğer işlemler tarafından üzerine yazılabilir. Ancak bu, elemanın bellekten silindiği anlamına gelmez; sadece o bellek alanının bir sonraki ekleme işlemi için kullanılabilir hale geldiği anlamına gelir. Dolayısıyla, stack veri yapısında elemanlar sadece üzerlerinden geçici olarak çıkarılır, ancak bellekteki alanları hala rezerve edilmiş ve kullanılabilir durumdadır.
}

void push(int a, stack * s){

    if(s->dizi == NULL){ //tanımlanan stack'e, dizi tanımı yapılıyor.
        s->dizi = (int *) malloc(sizeof(int)*2);
    }

    if(s->tepe >=s-> boyut - 1){ //dizi boyutu dolduğunda tepe ve boyut sayıları eşit olurlar.

        int * dizi2 = (int *) malloc(sizeof(int)*s->boyut*2);

        for(int i=0; i < s->tepe; i++){
            dizi2[i] = s->dizi[i];
        }

        free(s->dizi);
        s->dizi = dizi2;
        s->boyut *= 2;
    }

    s->dizi[s->tepe++] = a;
}

int peek(stack * s){
    if (s->tepe <= 0)
    {
        printf("%s\n", "dizi boss");
        return -1;
    }
    
    return s->dizi[s->tepe - 1];
}

void bastir(stack * s){
    printf("boyut: %d ",s->boyut);
    for (int i = 0; i < s->tepe; i++)
    {
        printf("%d ", s->dizi[i]);
    }
    printf("\n");
    
};

