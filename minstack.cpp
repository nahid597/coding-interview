#include<bits/stdc++.h>

using namespace std;
#define mx 5

struct st{
    int arg[mx];
    int top;
};

st s1,s2;

void push(int data)
{
    if(s1.top == mx)
    {
        cout << "stack is full" << endl;
        return;
    }

    s1.arg[s1.top++] = data;

    if(s2.top == 0)
    {
        s2.arg[s2.top++] = data;
    }
    else
    {
        int t = s2.arg[s2.top-1];

        if(data < t)
        {
           s2.arg[s2.top++] = data;
        }
        else
        {
            s2.arg[s2.top++] = t;
        }
    }

}

int pop()
{
    if(s1.top == 0)
    {
        cout << "stack is empty" << endl;
        return -1;
    }

    s1.top--;

    int data = s1.arg[s1.top];

    cout <<"top s2 " << s2.top << endl;
    s2.top--;
    //s2.arg[s2.top];

    return data;
}

int getMin()
{
    return s2.arg[s2.top-1];
}

int main()
{
    s1.top = 0;
    s2.top = 0;

    push( 18);
    push( 19);
    //push( 15);
    push(29);
    push(16);

    int m = getMin();
    cout << m << endl;

    int p = pop();
    cout << "pop vlaue " << p << endl;

     m = getMin();
    cout << m << endl;


    return 0;
}
