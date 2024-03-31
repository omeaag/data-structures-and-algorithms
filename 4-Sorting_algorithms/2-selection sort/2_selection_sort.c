#include <stdio.h>

void selection_sort(int a[],int b){
   
    for (int i = 0; i < b; i++)
    {
        int key = i;
        for (int j = i; j < b-1; j++)
        {
            if(a[key] > a[j+1])
            {
                key = j+1; 
            }
            
        }
        int temp = a[i];
        a[i] = a[key];
        a[key] = temp;
    }
    
}

int main(){
    int dizi[] = { -2, 45, 0, 11, -9};
    int length = sizeof(dizi)/sizeof(dizi[0]);

    selection_sort(dizi,length);

    for (int i = 0; i < length; i++)
    {
        printf("%d ",dizi[i]);
    }
    

    return 0;
}
