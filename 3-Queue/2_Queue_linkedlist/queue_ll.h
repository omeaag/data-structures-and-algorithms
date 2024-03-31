#ifndef queue_ll
#define queue_ll

struct n{
    int data;
    struct n * next;
};

typedef struct n node;

struct q {
    node * r;
    int boyut;
};
typedef struct q queue;

queue * tanim();
node * deque(queue * q);
node * enque(int a, queue * q);
void bastir(queue * q);


#endif