#include<bits/stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int grid[a+1][b+1] = {0};

    for(int i = 0; i < b; i++)
    {
        grid[0][i] = 1;
    }


    for(int i = 0; i < a; i++)
    {
         grid[i][0] = 1;
    }

    for(int i = 1; i < a; i++)
    {
        for(int j = 1; j < b; j++)
        {
            cout << grid[i-1][j] << "  " << grid[i][j-1] << endl;
            grid[i][j] = grid[i-1][j] + grid[i][j-1];
        }
    }

    cout << grid[a-1][b-1] << endl;

    return 0;
}
