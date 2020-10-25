#include<bits/stdc++.h>

using namespace std;

#define mx 5

typedef struct st {
    int data[mx+1];
    int head, tail, q1;
} qe;

void enQueue(int data, qe *q)
{
    if(q->head == (q->tail + 1 ) % (mx + 1))
    {
       cout << "queue is full" << endl;
       return;
    }

    q->data[q->tail] = data;
    q->tail = (q->tail + 1) % (mx + 1);
    q->q1 = (q->q1 + 1) % (mx + 1);
}

int deQueue(qe *q)
{
    if(q->head == q->tail)
    {
        cout << "queue is empty" << endl;
        return -1;
    }

    int item = q->data[q->q1 - 1];
    q->head = (q->head + 1) % (mx + 1);
    q->q1 = (q->q1 - 1) % (mx + 1);

    return item;
}

int main()
{
    qe arg;

    arg.head = arg.tail = arg.q1 = 0;

    enQueue(5, &arg);
    enQueue(15, &arg);
    enQueue(25, &arg);
    enQueue(25, &arg);

    int data;

    data = deQueue(&arg);
    cout << data << endl;

    data = deQueue(&arg);
    cout << data << endl;

    data = deQueue(&arg);
    cout << data << endl;

    data = deQueue(&arg);
    cout << data << endl;

    return 0;
}

