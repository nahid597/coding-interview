#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n;

  cin  >>n;

  int x[n+1];

  for(int i = 0; i < n; i++)
  {
     cin >> x[i];
  }

  int mx = INT_MIN, curs = 0;

  /// o(n2) complexcity
 /* for(int i = 0; i < n; i++)
  {
     mx = max(mx, x[i]);

     curs = x[i];

     for(int j = i +1; j < n; j++)
     {
        curs += x[j];

        mx = max(curs, mx);
     }
  }*/

  /// o(n) complexcity
  for(int i = 0; i < n; i++)
  {

    curs += x[i];

    mx = max(mx, curs);

    if(curs < 0)
      curs = 0;
  }



  cout << mx << endl;



    return 0;
}
