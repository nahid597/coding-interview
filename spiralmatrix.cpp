#include<bits/stdc++.h>

using namespace std;

int n, m;


int main()
{

    cin >> n >> m;

    int matrix[n+1][m+1];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int arg[n * m + 2];

    int top, bottom, left, right, direction = 0, k = 0;

    top = 0; bottom = n; left = 0; right = m;

    while(top < bottom)
    {
        //cout << "nahid" << endl;
        if(direction == 0)
        {
           /// traverse left to right
           for(int i = left; i < right; i++)
           {
                arg[k++] = matrix[top][i];
                //cout << "l -> r " << arg[k-1] << endl;
           }
        }

        if(direction == 1)
        {
           /// traverse top to bottom
           for(int i = top + 1; i < bottom; i++)
           {
                arg[k++] = matrix[i][right-1];
                //cout << "t -> b " << arg[k-1] << endl;
           }
        }

        if(direction == 2)
        {
           /// traverse right to left
           for(int i = right-1; i > left; i--)
           {
                arg[k++] = matrix[bottom-1][i-1];
               // cout << "r -> l " << arg[k-1] << endl;
           }
        }
        if(direction == 3){
          /// traverse bottom to top
           for(int i = bottom-1; i > top + 1; i--)
           {
                arg[k++] = matrix[i-1][left];
               // cout << "b -> t " << arg[k-1] << endl;
           }
        }

        if((direction + 1) % 4 == 0)
        {
            top = top + 1;
            left = left + 1;
            bottom = bottom - 1;
            right = right - 1;
        }

        direction = (direction + 1) % 4;
    }

    for(int i = 0; i < k; i++)
    {
       cout << arg[i] << " ";
    }


    return 0;
}
