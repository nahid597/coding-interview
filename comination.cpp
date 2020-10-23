#include<bits/stdc++.h>

using namespace std;

int number[100], used[100], check = 1;


void permutation(int pos, int n, int k)
{
    if(pos == k + 1)
    {
        for(int i = 1; i <= k; i++)
        {
            cout << number[i] << " ";
        }
        cout << endl;
        return;
    }

    for(int i = check; i <= n; i++)
    {
        if(used[i])
          continue;

        check = i;
        used[i] = 1;
        number[pos] = i;
        //cout << number[pos] << endl;
        /// this permutation for position set
        permutation(pos+1, n, k);
        used[i] = 0;
    }
}


int main()
{
    int n, k;
    cin >> n >> k;

    permutation(1, n, k);

    return 0;
}

