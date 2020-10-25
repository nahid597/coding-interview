#include<bits/stdc++.h>

using namespace std;

#define mx 5

typedef struct st {
  int data;
   st *next, *prev;
} Node;

Node *newNode(int data)
{
    Node *new_node = (Node*) malloc(sizeof(Node));

    new_node->data = data;
    new_node->next=new_node->prev = NULL;
    return new_node;
}

//structure of deque;

class Deque{
    Node *font, *rear;
    int sz;
public:
    Deque()
    {
        font = rear = NULL;
        sz = 0;
    }

    bool isEmpty()
    {
        return (font == NULL);
    }

    void insertFront(int data)
    {
        Node *new_node = newNode(data);

        if(new_node == NULL)
        {
           cout << "overflow" << endl;
           return;
        }

        if(font == NULL)
        {
           font = rear = new_node;
        }
        else
        {
            //Node *temp = font;

            new_node->next = font;
            font->prev = new_node;
            font = new_node;
        }

        sz++;
    }

    void insertRear(int data)
    {
        Node *new_node = newNode(data);

        if(new_node == NULL)
        {
           cout << "overflow" << endl;
           return;
        }

        if(rear == NULL)
        {
           font = rear = new_node;
        }
        else
        {
            //Node *temp = font;

            new_node->prev = rear;
            rear->next = new_node;
            rear = new_node;
        }

        sz++;
    }

    void popFront()
    {
       if(isEmpty())
       {
          cout << "queue is empty" << endl;
          return ;
       }

       Node *temp = font;
       int data = font->data;

       font = font->next;

       // if only one element

       if(font == NULL)
       {
           rear = NULL;
       }

       font->prev = NULL;

       free(temp);

       sz--;

       //return data;
    }

    void popRear()
    {
       if(isEmpty())
       {
          cout << "queue is empty" << endl;
          return;
       }

       Node *temp = rear;
       int data = rear->data;

       rear = rear->prev;

       // if only one element

       if(rear == NULL)
       {
           font = NULL;
       }

       rear->next = NULL;

       free(temp);

       sz--;

       //return data;
    }

    int getFont()
    {
        if(isEmpty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        else
        {
            return font->data;
        }
    }

    int getRear()
    {
        if(isEmpty())
        {
            cout << "queue is empty" << endl;
            return -1;
        }
        else
        {
            return rear->data;
        }
    }

};


int main()
{

    Deque dq;

    dq.insertFront(5);
    dq.insertFront(15);
    dq.insertFront(25);

    dq.insertRear(50);
    dq.insertRear(60);

    int p1 = dq.getFont();
    cout << p1 << endl;

    cout << "after font delete" << endl;

     dq.popFront();
     dq.popFront();
     //dq.popFront();
     //dq.popFront();

     dq.popRear();

     p1 = dq.getFont();
    cout << p1 << endl;

     int p2 = dq.getRear();
    cout << p2 << endl;



    return 0;
}
