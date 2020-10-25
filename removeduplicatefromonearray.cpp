
#include<bits/stdc++.h>

using namespace std;

int main()
{

    int n1;

    cin >> n1;

    int *x1 = new int[100];

    for(int i = 0; i < n1; i++)
    {
        cin >> x1[i];
    }

    int  cnt = 0;

    for(int i = 0; i < n1; i++)
    {
        for(int j = i+1; j < n1; j++)
        {
           if(x1[i] == x1[j])
           {
                cnt++;

              for(int l = j; l < n1; l++)
              {
                x1[l] = x1[l+1];
              }

              n1--;
              i--;
           }
        }
    }


    cout << "size of " << n1 - cnt << endl;
    for(int i = 0; i < n1; i++)
    {
        cout << x1[i] << " ";
    }
     cout << endl;

    return 0;
}
