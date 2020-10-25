#include<bits/stdc++.h>

using namespace std;

#define mx 5

typedef struct st{

    int data[mx];
    int top1, top2;

} st;

void push1(st *s, int data)
{
    cout << "tp1 " << s->top1 << " " << s->top2 << endl;
    if(s->top1 < s->top2)
    {
        s->data[s->top1++] = data;

    }
    else
    {
        cout << "stack is full" << endl;
        return;
    }

}

void push2(st *s, int data)
{
    cout << "tp2 " << s->top1 << " " << s->top2 << endl;
    if(s->top1 < s->top2)
    {
       s->top2--;
        s->data[s->top2] = data;

    }
    else
    {
        cout << "stack is full" << endl;
        return;
    }

}

int pop1(st *s)
{
    if(s->top1 >= 0)
    {

        int data = s->data[s->top1 - 1];
        s->top1--;
        return data;

    }

    else
    {
        cout << "stack is empty" << endl;
        return -1;
    }

}

int pop2(st *s)
{
    if(s->top2 < mx)
    {

        int data = s->data[s->top2];
        s->top2++;
        return data;
    }

    else
    {
        cout << "stack is empty" << endl;
        return -1;
    }

}

int main()
{
   st arg;

   arg.top1 = 0;
   arg.top2 = mx ;

   push1(&arg, 5);
   push1(&arg, 15);
   push1(&arg, 25);
   push2(&arg, 35);
   push2(&arg, 45);

   int p = pop1(&arg);
   cout << p << endl;
    p = pop1(&arg);
   cout << p << endl;
    p = pop2(&arg);
   cout << p << endl;
    p = pop2(&arg);
   cout << p << endl;
   p = pop2(&arg);
   cout << p << endl;
    p = pop1(&arg);
   cout << p << endl;

    return 0;
}

