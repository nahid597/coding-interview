#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    int *arg = (int*) malloc(100 * sizeof(int));
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arg[i];
    }

    int cnt = 0, sum = 0, ans = 0;

    for(int i = 0; i < n; i++)
    {
        cnt++;
        for(int j = 0; j < n; j++)
        {
            sum = 0;

            for(int k = 0; k < cnt; k++)
            {
                sum += arg[k + j];
            }

            ans = max(ans, sum);

        }
    }

    cout << ans << endl;

    return 0;
}

