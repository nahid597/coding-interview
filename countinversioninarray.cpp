#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

   // int *arg = new int(n+1);
   int *arg = (int*) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++)
    {
        cin >> arg[i];
    }

    int cnt = 0;

    map<int,int>mp;
    map<int,int>::iterator it;

    pair<int,int> pa;

    for(int i = 0; i < n; i++)
    {
        for(int j = n - 1; j >= i + 1; j--)
        {
            if(arg[i] > arg[j] && i < j)
            {
                cnt++;
                pa.first = arg[i];
                pa.second = arg[j];
            }
        }
    }

    cout << cnt << endl;

    /*for(it = mp.begin(); it != mp.end(); it++)
    {
        cout << "( " << it->first << " , " << it->second << " )" << endl;
    }*/

    for(auto &x : pa)
    {

    }

    return 0;
}
