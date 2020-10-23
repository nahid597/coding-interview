#include<bits/stdc++.h>

using namespace std;

long long x;

long long pow(int a, int n)
{
    if(n == 0)
      return 1;

    if(n % 2 != 0)
       return a * pow(a, n-1);

    x = pow(a, n / 2);

    x = x * x;

    return x;

}

int main()
{
   int n, a;

   cin >> a >> n;

   long long p = pow(a, n);

   cout << p << endl;

    return 0;
}
