#include<iostream>

using namespace std;

#define max_size 2

struct st{
    int data[max_size];
    int top;
};

void push(struct st *stack ,int data)
{
    if(stack->top > max_size-1)
    {
       cout << "stack is full" << endl;
       return;
    }

    cout << stack->top << endl;

    stack->data[stack->top] = data;
    stack->top++;
}

int pop(struct st *stack)
{
    if(stack->top == 0)
    {
        cout << "stack is empty " << endl;
        exit(1);
    }

    int item;
    stack->top--;
    item = stack->data[stack->top];

    return item;
}

int main()
{

    struct st arg;

    arg.top = 0;

    push(&arg, 5);
    push(&arg, 15);
    push(&arg, 25);

    int item;

   item = pop(&arg);
   cout << item << endl;

      item = pop(&arg);
   cout << item << endl;

      item = pop(&arg);
   cout << item << endl;

      item = pop(&arg);
   cout << item << endl;



    return 0;
}
