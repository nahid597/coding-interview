#include<bits/stdc++.h>

using namespace std;

int main()
{
     int n, k;
    cin >> n;

    int a[n+1], d[n+1];

    cout << "Enter arrivals time" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter departures time" << endl;
    for(int i = 0; i < n; i++)
    {
        cin >> d[i];
    }


    cout << "Enter rooms number" << endl;

     cin >> k;

     int stR = k;
     int cnt = 0;

     bool ch = true;

     for(int i = 0; i < n; i++)
     {
        // stR = k;
        cnt = 0;

        for(int j = 0; j < i; j++)
        {
            if(a[i] <= d[j])
            {
               // stR--;
               cnt++;
            }
           /* else
            {
               if(stR < k)
                stR++;
            }*/

        }

        if(cnt >= k)
        {
           ch = false;
           break;
        }

        /*if(stR <= 0)
        {
            ch = false;
            break;
        }
        else
         ch = true;*/
     }

     cout << ch << endl;


    return 0;
}

