#include<bits/stdc++.h>

using namespace std;

int bs(int arg[], int key, int l , int r, int s)
{
    //int s = 0;

    if(l <= r)
    {
        cout << l << " " << r << endl;
        int m = (l+r)/2;

        if(arg[m] == key)
        {
            //cout << "nahid" <<endl;
            s = m;
            //return m;

        };

        if(key <= arg[m])
        {
           return bs(arg, key, l , m-1,s);
        }
        else
        {
           return bs(arg, key, m + 1, r,s);
        }

    }

    if(s == 0)
       s = l;
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

   int s = bs(x,key, 0, n, 0);

   cout << s << endl;

}
