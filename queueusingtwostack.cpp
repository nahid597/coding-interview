#include<bits/stdc++.h>

using namespace std;

struct Q
{
    stack<int>s1,s2;

    void enqueue(int data)
    {
        while(!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(data);

        while(!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int dequeue()
    {
       if(s1.empty())
       {
          cout << "Queue is empty" << endl;
          return -1;
       }

       int x = s1.top();
       s1.pop();

       return x;
    }

};

int main()
{
    Q p;

    p.enqueue(5);
    p.enqueue(7);
    p.enqueue(1);
    p.enqueue(4);

    int s = p.dequeue();
    cout << s << endl;

    s = p.dequeue();
    cout << s << endl;

     s = p.dequeue();
    cout << s << endl;

    s = p.dequeue();
    cout << s << endl;


    return 0;
}
