#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    int x[n+1], y[n+1];

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
        y[i] = x[i];
    }

    int start = 0, en = 0;

    sort(y , y + n);

    for(int i = 0; i < n; i++)
    {
        if(x[i] != y[i])
        {
            start = i;
            break;
        }
    }

    for(int i = n-1; i >= 0; i--)
    {
        if(x[i] != y[i])
        {
            en = i;
            break;
        }
    }

    cout << start << " -> " << en << endl;

    return 0;
}
