#include <stdio.h>

void bubble_sort(int dizi[] ,int n){
    int i,j, temp;

    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-i-1; j++)
        {
            if(dizi[j] > dizi[j+1])
            {
                temp = dizi[j];
                dizi[j] = dizi[j+1];
                dizi[j+1] = temp; 
            }
            
        }
        
    }

}

int main(){

    int dizi[]= {5,9,4,6,8,7,3,1,2,0,34,3,1,5};
    int n = sizeof(dizi)/sizeof(dizi[0]);

    for (int i = 0; i < n; i++)
    {
        printf("%d ",dizi[i]);
    }  
    printf("\n");

    bubble_sort(dizi, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ",dizi[i]);
    }
    return 0;
    
}