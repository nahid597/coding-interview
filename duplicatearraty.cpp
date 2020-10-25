#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int *arg = (int*)malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
    {
        cin >> arg[i];
    }

    int uni[n+1];
    int index = 1;
    uni[0] = arg[0];

    /*sort(arg , arg + n);

    for(int i = 1; i < n; i++)
    {
       if(arg[i] != arg[i-1])
       {
           uni[index++] = arg[i];
       }
    }

    cout << index << endl;*/

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arg[i] == arg[j])
            {
                for(int l = j; l < n; l ++)
                {
                    arg[l] = arg[l+1];
                }

                i--;
                j--;
                n--;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        cout << arg[i] << endl;
    }

}
