#include<bits/stdc++.h>

using namespace std;

struct st{
    int d;
    int p;
};

bool compare(st s1, st s2)
{
   return s1.d < s2.d;
}

int binarySearch(int arg[], int l, int r, int key)
{
    if(l <= r)
    {
        int mid = ( l + r) / 2;
       // cout << arg[mid] << " " << key << endl;
       cout << mid << " " << key << endl;
        if(arg[mid] == key)
        {
           return mid;
        }

        if(key < arg[mid])
          return binarySearch(arg, l, mid -1, key);
        else
           return binarySearch(arg, mid + 1, r, key);
    }

    return -1;
}

int main()
{
    int n;
    cin >> n;

    int x[n+1];
    st s[n+1];

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        s[i].d = x[i];
        s[i].p = i;
    }

    sort(x, x + n);
    sort(s, s + n, compare);

    for(int i = 0; i < n; i++)
    {
       cout << s[i].d << " , " << s[i].p << endl;
    }

     for(int i = 0; i < n; i++)
    {
        int target = 0 - x[i];
       // cout << "tar " << target << endl;
        int p = binarySearch(x,i+1, n -1, target);
        //cout <<"p"<< p <<endl;
        if(p != -1)
        {
           cout << i << " " << p << endl;
        }
    }

   // int p = binarySearch(x,0,n-1,x[n-1]);
    //cout << "pa" << p << endl;

    return 0;
}
