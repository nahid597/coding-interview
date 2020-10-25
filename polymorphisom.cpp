#include<bits/stdc++.h>

using namespace std;

class A {
    public:
        int id = 10;
        void display()
        {
            cout << "I am a A" << endl;
        }
};

class B: public A {
    public:

        void display()
        {
            cout << id << endl;
            cout << "I am a B" << endl;
        }
};

class C: public B {
    public:
        void display()
        {
             cout << id << endl;
            cout << "I am a C" << endl;
        }
};

int main()
{
    A ob1;
    B ob2;
    C ob3;

    ob1.display();
    ob2.display();
    ob3.display();

    return 0;
}
