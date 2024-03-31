#ifndef stack_linkedlist
#define stack_linkedlist

struct n {
    int x;
    struct n * next;
};
typedef struct n node;

struct s {
    node * r;
    int boyut;
};
typedef struct s stack;

stack * tanim();
int pop(stack * s);
node * push(int a, stack * s);
int peek(stack * s);
void bastir(stack * s);

#endif