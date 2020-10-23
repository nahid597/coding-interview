#include<bits/stdc++.h>

using namespace std;

#define mx 3

struct st{

    int data[mx+1];
    int head, tail;
};

void enQueue(st *qe, int data)
{
    if(qe->head == (qe->tail + 1) % (mx + 1))
    {
        cout << "queue is full" << endl;
        return ;
    }
    qe->data[qe->tail] = data;
    qe->tail = (qe->tail + 1) % (mx + 1);
}

int deQueue(st *qe)
{
    if(qe->head == qe->tail)
    {
        cout << "queue is empty" << endl;
        return -1;
    }

    int data = qe->data[qe->head];
    qe->head = (qe->head + 1) % (mx + 1);
    return data;
}

int main()
{
    st arg;
    arg.head = 0;
    arg.tail = 0;

    enQueue(&arg, 5);
    enQueue(&arg, 15);
    enQueue(&arg, 5);
    enQueue(&arg, 35);

    int p1, p2;

    p1 = deQueue(&arg);
    cout << p1 << endl;
    p1 = deQueue(&arg);
    cout << p1 << endl;
    p1 = deQueue(&arg);
    cout << p1 << endl;
    p2 = deQueue(&arg);
    cout << p2 << endl;
     p2 = deQueue(&arg);
    cout << p2 << endl;


    return 0;
}
