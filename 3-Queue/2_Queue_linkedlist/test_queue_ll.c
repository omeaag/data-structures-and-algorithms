#include <stdio.h>
#include <stdlib.h>
#include "queue_ll.h"

int main(){
    queue * q1 = tanim();

    enque(10,q1);
    bastir(q1);
    enque(20,q1);
    enque(30,q1);
    enque(40,q1);
    bastir(q1);
    enque(50,q1);
    enque(60,q1);
    enque(70,q1);
    bastir(q1);
    enque(80,q1);
    bastir(q1);
    printf("\n-------------------------\n");
    deque(q1);
    bastir(q1);
    deque(q1);
    deque(q1);
    bastir(q1);
}