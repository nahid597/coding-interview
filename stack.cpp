#include<bits/stdc++.h>

using namespace std;

#define mx 3

struct st{
    int top;
    int data[mx];
};

void push(st *str, int data)
{
    if(str->top == mx)
    {
        cout << "stack is full" << endl;
        return;
    }
    str->data[str->top++] = data;
}

int pop(st *str)
{
    if(str->top == 0)
    {
        cout << "stack is empty"<< endl;
        return -1;
    }

    str->top--;
    return str->data[str->top];
}

int top(st *str)
{
    if(str->top == 0)
    {
        cout << "stack is empty"<< endl;
        return -1;
    }

    return str->data[str->top];
}

int main()
{

    st arg;

    arg.top = 0;

    push(&arg, 5);
    push(&arg, 15);
    push(&arg, 25);
    push(&arg, 35);

    int p;

    p = pop(&arg);
    cout << p << endl;
     p = pop(&arg);
    cout << p << endl;
     p = pop(&arg);
    cout << p << endl;

    p = pop(&arg);
    cout << p << endl;


    return 0;
}
