#include<bits/stdc++.h>

using namespace std;

int bs1(int arg[], int key, int l , int r, int s, bool flag)
{
    //int s = 0;

    if(l <= r)
    {
       // cout << l << " " << r << endl;
        int m = (l+r)/2;

        if(arg[m] == key)
        {
            //cout << "nahid" <<endl;
            s = m;
            flag = true;
            //return m;

        };

        if(key <= arg[m])
        {
           return bs1(arg, key, l , m-1,s, flag);
        }
        else
        {
           return bs1(arg, key, m + 1, r,s, flag);
        }

    }

    if(s == 0 && !flag)
       s = -1;
    //cout << l << endl;

    return s;
}

int bs2(int arg[], int key, int l , int r, int s, bool flag)
{
    //int s = 0;

    if(l <= r)
    {
       // cout << l << " " << r << endl;
        int m = (l+r)/2;

        if(arg[m] == key)
        {
            //cout << "nahid" <<endl;
            s = m;
            flag = true;
            //return m;

        };

        if(key < arg[m])
        {
           return bs2(arg, key, l , m-1,s, flag);
        }
        else if(key >= arg[m])
        {
           return bs2(arg, key, m + 1, r,s, flag);
        }

    }

    if(s == 0 && !flag)
       s = -1;
    //cout << l << endl;

    return s;
}

int main()
{
    int n;

    cin >> n;

   // int x[n+1];

   int *x = new int[100];

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int key;

    cin >> key;

   int s1 = bs1(x,key, 0, n, 0, false);
   int s2 = bs2(x,key, 0, n, 0,false);

   cout << s1 << " " << s2 << endl;

   int total =  (s2 - s1) + 1;

   cout << "total " << total << endl;

}
