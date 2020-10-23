#include<bits/stdc++.h>

using namespace std;

#define mx 3

struct st {
    int head;
    int tail;
    int data[mx + 1];
};

void enqueue(st *qe, int data) {
    if(qe->head == (qe->tail + 1) % (mx + 1))
    {
        cout << "queue is full" << endl;
        return ;
    }
    qe->data[qe->tail] = data;
    qe->tail = (qe->tail + 1) % (mx + 1);
}

int dequeue(st *s) {
     if(s->head == s->tail ) {
        cout << "queue is empty" << endl;
        return -1;
    }

    int data = s->data[s->head];
    s->head = (s->head + 1) % (mx + 1);
    return data;

}

int main()
{

   st arg;
    arg.head = 0;
    arg.tail = 0;

    enqueue(&arg, 5);
    enqueue(&arg, 15);
    enqueue(&arg, 25);
    enqueue(&arg, 35);

    int p1, p2;

    p1 = dequeue(&arg);
    cout << p1 << endl;
    p1 = dequeue(&arg);
    cout << p1 << endl;
    p1 = dequeue(&arg);
    cout << p1 << endl;
    p1 = dequeue(&arg);
    cout << p1 << endl;

    return 0;
}
