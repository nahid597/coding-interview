#include<bits/stdc++.h>

using namespace std;

int countTriangles(int x[], int n)
{
   int cnt = 0,k;

   for(int i = 0; i < n -2; i++)
   {
     k = i + 2;
      for(int j = i +1; j < n-1; j++)
      {
        //k = j + 1;

          while(k < n && x[i] + x[j] > x[k])
          {
             cout << x[i] << " " << x[j] << " " << x[k] << endl;
             k++;
             //if(j != k)
              // cnt++;
          }

          if(k > j)
               cnt += k - j -1;
      }
   }
   //cout << cnt <<endl;

    return cnt;
}

int main()
{

    int n;

    cin >> n;

    int x[n+1];

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

   int ans = countTriangles(x,n);

   cout << ans <<endl;


    return 0;
}
