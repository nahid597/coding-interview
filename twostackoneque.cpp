#include<iostream>

using namespace std;

#define mx 5

struct st {
  int top, ctop;
  int data[mx + 1];
};


void push1(st *s, int data) {
//cout << s->top << " " << s->ctop << endl;
    if(s->top >= s->ctop) {
        cout << "stack1 is full" << endl;
        return;
    }
    s->data[s->top++] = data;
}

void push2(st *s, int data) {
//cout << s->top << " " << s->ctop << endl;
    if(s->top >= s->ctop) {
        cout << "stack2 is full" << endl;
        return;
    }
    s->ctop--;
    s->data[s->ctop] = data;
}

int pop1(st *s) {
    if(s->top == 0)
    {
        cout << "stack1 is empty" << endl;
        return -1;
    }
    s->top--;
    return s->data[s->top];
}

int pop2(st *s) {
    if(s->ctop == mx)
    {
        cout << "stack2 is empty" << endl;
        return -1;
    }
    return s->data[s->ctop++];
}


int main()
{
   st arg;
   arg.top = 0;
   arg.ctop = mx;

   push1(&arg, 15);
   push1(&arg, 25);
   push1(&arg, 35);

   push2(&arg, 45);
   push2(&arg, 55);
   push2(&arg, 65);

   int p1 = pop1(&arg);
   cout << p1 << endl;
    p1 = pop1(&arg);
   cout << p1 << endl;
   p1 = pop1(&arg);
   cout << p1 << endl;
    p1 = pop2(&arg);
   cout << p1 << endl;
   p1 = pop2(&arg);
   cout << p1 << endl;
   p1 = pop2(&arg);
   cout << p1 << endl;

    return 0;
}
