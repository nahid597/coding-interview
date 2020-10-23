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

    int i = 0 , j = n-1;

    while(i < j)
    {
        int sum = x[i] + x[j];

        if(sum == 0)
        {
            cout << x[i] << " " << x[j] << endl;
            break;
        }
        else if(sum > 0)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return 0;
}


