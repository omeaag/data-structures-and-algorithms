#include <stdio.h>
#include <stdlib.h>
#include "queue_arr.h"

int main(){

    for (int i = 0; i < 10; i++)
    {
        enque(i*10);
    }

    for (int i = 0; i < 9; i++)
    {
        deque(i*10);
    }
    
    bastir();
    enque(33);
    enque(44);
    enque(55);
    bastir();
    enque(111);
    enque(222);
    enque(333);
    enque(444);
    enque(555);
    enque(666);
    enque(777);
    bastir();
    for (int i = 0; i < 10; i++)
    {
        deque();
    }
    
    bastir();

}