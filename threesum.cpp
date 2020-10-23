#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int x[n+1];

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    sort(x, x + n);

    set<int>st;

    int i = 0 , j , k;

    while(i < n - 2)
    {
        j = i + 1;
        k = n - 1;

        while(j < k)
        {
            int sum = x[i] + x[j] + x[k];

            //cout << sum << endl;

            if(sum == 0)
            {
                cout << x[i] << " " << x[j] << " " << x[k] << endl;
                //st.insert(x[i]);
                //st.insert(x[j]);
                //st.insert(x[k]);
                while(x[j] == x[j+1] && j < k -1)
                {
                    j++;
                }

                 while(x[k] == x[k-1] && j < k -1)
                {
                    k--;
                }
                j++;
            }
            else if(sum > 0)
            {
               k--;
            }
            else
            {
               j++;
            }

        }

        while(x[i]== x[i+1] && i < n -2)
        {
          i++;
        }
        i++;
    }

    /*set<int>::iterator it;

    for(it = st.begin(); it != st.end(); it++)
    {
       cout << *it << endl;
    }*/


    return 0;
}

