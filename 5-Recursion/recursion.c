#include <stdio.h>

int recursion(int sayi){
    if (sayi == 2)
    {
        return sayi;
    }
    
    return sayi * recursion(sayi - 1);
}

int main(){
    int sonuc = recursion(7);
    printf("%d ", sonuc);
}