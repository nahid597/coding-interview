#include<bits/stdc++.h>

using namespace std;

int main()
{
   int n;
   cin >> n;

   //int *arg = new int[n+1];
   int arg[10000]= {0};

   for(int i = 0; i < n; i++)
   {
      cin >> arg[i];
   }

   int sum = 0, st = 0, ans = INT_MIN;
    for(int i = 0; i < n; i++)
   {
      st++;
      for(int j = 0;  j< n ; j++)
      {
         sum = 0;

        for(int k = 0; k < st; k++)
        {
            sum += arg[k + j];
        }
        ans = max(ans, sum);
      }
   }

   cout << ans << endl;

    return 0;
}
