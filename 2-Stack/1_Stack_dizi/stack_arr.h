#ifndef stack_arr
#define stack_arr

struct s{
    int * dizi;
    int tepe;
    int boyut;
};
typedef struct s stack;
stack * tanim();
int pop(stack*);
void push(int,stack*);
int peek(stack *);
void bastir(stack *);

#endif