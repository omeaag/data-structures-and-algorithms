#include <stdio.h>
#include <stdlib.h>
#include "stack_linkedlist.h"

int main(){
    
    stack * s1 = tanim();
    stack * s2 = tanim();

    for (int i = 0; i < 10; i++)
    {
        push(i*5,s1);
    }
    
    bastir(s1);
    bastir(s2);
    for (int i = 0; i < 10; i++)
    {
        push(pop(s1),s2);
    }
    
    bastir(s1);
    bastir(s2);
}