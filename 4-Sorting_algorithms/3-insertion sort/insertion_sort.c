#include <stdio.h>

void insertion_sort(int dizi[], int n){
    int i, j,temp;
    for(i = 1; i < n; i++)
    {
        j = i - 1;
        temp = dizi[i];

        while ( j > -1 && dizi[j] > temp)
        {
            dizi[j+1] = dizi[j];
            j--; 
        }
        dizi[j + 1] = temp;
        
    }
}

int main(){
    int dizi[] = {64, 25, 12, 22, 11};
    int n = sizeof(dizi)/sizeof(dizi[0]);

    insertion_sort(dizi,n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", dizi[i]);
    }
    
}