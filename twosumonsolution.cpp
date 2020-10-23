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

    unordered_map<int,int>ump;

    for(int i = 0; i < n; i++)
    {
        ump[x[i]] = 1;
    }

    int num = 0;
    for(int i = 0; i < n; i++)
    {
        num = x[i] * -1;
        if(ump[num] == 1)
        {
           cout << x[i] << " " << num << endl;
           break;
        }
    }



    return 0;
}
