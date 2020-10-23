#include<iostream>

using namespace std;

#define mx 5
typedef struct st {
    int data[ mx + 1];
    int head, chead;
    int tail, ctail;
    int cnt;
} dq;

bool isFull(dq *q) {
//cout << q->cnt << endl;
  if(q->cnt == mx)
  {
     return true;
  }
  return false;
}

bool isEmpty(dq *q) {
  if(q->cnt == 0)
  {
     return true;
  }
  return false;
}

void inInHead(dq *q, int data) {
    if(isFull(q)) {
       cout << " queue is full" << endl;
       return;
    }

    q->data[q->tail] = data;
    q->tail = (q->tail + 1) % (mx + 1);
    q->cnt++;
}

void inInTail(dq *q, int data) {
    if(isFull(q)) {
       cout << " queue is full" << endl;
       return;
    }

    q->data[q->ctail] = data;
    q->ctail = (q->ctail - 1);
    if((q->ctail + 1) == 0)
      q->ctail = mx - 1;
    q->cnt++;
}

int deinHead(dq *q) {
    if(isEmpty(q)) {
      cout << "d is empty" << endl;
    }
    int data = q->data[q->head];
    q->head = (q->head+1) % (mx + 1);
    q->cnt--;
    return data;
}

int deinTail(dq *q) {
    if(isEmpty(q)) {
      cout << "d is empty" << endl;
    }
    int data = q->data[q->chead];
    q->chead = (q->chead - 1);
    if((q->chead + 1) == 0) {
      q->chead = mx - 1;
    }
    q->cnt--;
    return data;
}

int main()
{
   dq arg;

   arg.cnt = 0;
   arg.head = 0;
   arg.chead = mx - 1;
   arg.tail = 0;
   arg.ctail = mx - 1;


   inInHead(&arg, 5);
   inInHead(&arg, 15);
   inInHead(&arg, 25);

   inInTail(&arg, 35);
   inInTail(&arg, 45);
   inInTail(&arg, 55);

   int p1, p2;
   p1 = deinHead(&arg);
   cout << p1 << endl;
    p1 = deinHead(&arg);
   cout << p1 << endl;
    p1 = deinHead(&arg);
   cout << p1 << endl;
    p1 = deinHead(&arg);
   cout << p1 << endl;

   p2 = deinTail(&arg);
   cout << p2 << endl;

    return 0;
}
