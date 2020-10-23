#include<bits/stdc++.h>

using namespace std;

struct Interval{
    int start;
    int end;
};

bool compare(Interval i1, Interval i2)
{
    return (i1.start < i2.start);
}

void mergeInterval(Interval arg[], int n)
{
    sort(arg, arg + n, compare);

    stack<Interval>s;

    s.push(arg[0]);

    for(int i = 0; i < n; i++)
    {
        cout << arg[i].start << " " << arg[i].end << endl;
    }

    for(int i = 1; i < n; i++)
    {
        Interval top = s.top();

        if(top.end < arg[i].start)
        {
            /// not overlap
            s.push(arg[i]);
        }
        else if(top.end < arg[i].end)
        {
            top.end = arg[i].end;
            s.pop();
            s.push(top);
        }
    }

    while(!s.empty())
    {
        Interval t = s.top();

        cout << t.start << " , " << t.end << endl;

        s.pop();
    }
}

int main()
{
    Interval arg[] = {
        {6,8},
        {1,9},
        {2,4},
        {4,7}
    };

    int n = sizeof(arg)/ sizeof(arg[0]);

    mergeInterval(arg, n);

    return 0;
}
