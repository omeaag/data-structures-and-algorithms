#include <stdio.h>

void selection_sort(int a[],int b){
   
    for (int i = 0; i < b; i++)
    {
        int key = i; //sıralanmamış ilk elemandan başlar
        for (int j = i + 1; j < b; j++) // key değerinden bir sonraki elemandan başlayıp dizinin sonuna kadar her elemanının indeksini kapsayan bir döngü
        {
            if(a[key] > a[j]) // key değerini dizinin her elemanı ile karşılaştırırız
            {
                key = j; // eğer key indeksindeki eleman karşılaştırdığımız elemandan büyükse, demek ki dizinin en küçük elemanı değildir. biz key indeksinde dizinin en küçük elemanının indeksini tutmayı hedefliyoruz.
                //key indeksi değişebilir, j döngüsü dizinin sonuna kadar ilerlemeye devam eder. yani burada key indeksinde tuttuğumuz küçük elemanın indeksi, dizinin sonuna kadar tüm sıralanmamış elemanlarla karşılaştırılır, en küçük değeri bulmak için. 
            }
            
        }
        //j döngüsü bittiğinde sıralanmamış elemanların en küçüğü bulunmuş demektir. burada swap işlemi yapıp en küçük değeri, sıralanmamış elemanların en başına (i indeksi) alırız.
       
        int temp = a[i];
        a[i] = a[key];
        a[key] = temp;
    }
    
}

int main(){
    int dizi[] = {5,9,4,6,8,7,3,1,2,0,34,3,1,5};
    int length = sizeof(dizi)/sizeof(dizi[0]);

    selection_sort(dizi,length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ",dizi[i]);
    }
    

    return 0;
}
