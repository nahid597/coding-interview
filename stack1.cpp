#include<bits/stdc++.h>

using namespace std;

#define mx 3

struct st {
  int top;
  int data[mx + 1];
};

void push(st *s, int data) {
  //cout << s->top << endl;
    if(s->top == mx) {
        cout << "stak full" << endl;
        return;
    }

    s->data[s->top++] = data;
}

int pop(st *s) {
    if(s->top == 0) {
        cout << "stack is empty" << endl;
        return -1;
    }

    s->top--;
    return s->data[s->top];
}

int top(st *s) {
    return s->data[s->top -1];
}

int main() {
    st s;
    s.top = 0;

    push(&s, 5);
    push(&s, 15);
    push(&s, 25);
    push(&s, 35);

    int p = pop(&s);
    cout << p << endl;

    return 0;
}
