#include<bits/stdc++.h>

using namespace std;

int main()
{
   int x, n;

   cout << "enter number" << endl;

   cin >> x;

   cout << "enter bit position" << endl;
   cin >> n;

   int bit, st[100];
   int s = (x >> n) & 1;

   cout << s << endl;


   for(int i = 0; i < n; i++)
   {
        bit = (1 << i);
        int p = bit & x;
        int t = p >> i;
        st[i] = t;

   }




   for(int i = n-1; i >= 0; i--)
      cout << st[i] << " ";



    return 0;
}
