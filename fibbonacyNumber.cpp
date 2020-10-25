#include<bits/stdc++.h>

using namespace std;

//using dynamic programming...

int m[1000000];

int fib(int n, int m[])
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(m[n] == 0)
        return m[n] = fib(n-1, m) + fib(n-2, m);

    else
    {
       cout << "nahid" << endl;
        return m[n];
    }


}

int main()
{
    int n;

    cin >> n;

    int ans = fib(n, m);

   long long m1[1000000];
   m1[1] = 1;
   m1[0] = 0;

   //for(int i = 2; i <= n; i++)
   //{
    //   m1[i] = m1[i-1] + m1[i-2];
   //}

    cout << ans << endl;


    return 0;
}
