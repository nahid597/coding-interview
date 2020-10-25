#include<bits/stdc++.h>

using namespace std;

int maxconnected(int matrix[6][7],int row,int col,int x,int y)
{

    if(row < 0 || col < 0 || row >= x || col >= y)
      return 0;
    if(matrix[row][col] == 0)
      return 0;

      int sz = 1;

      matrix[row][col] = 0;

    for(int r = row -1; r <= row + 1; r++)
    {
        for(int c = col - 1; c <= col + 1; c++)
        {
           if(r != row || c != col)
            sz += maxconnected(matrix, r, c, x, y);
        }

        //cout << row << " " << col << " " << sz << endl;
    }

    return sz;
}

int getmaxconnectcell(int matrix[6][7], int x,int y)
{

    int mx = 0;

   for(int row = 0; row < x; row++)
   {
       for(int col = 0; col< y; col++)
       {
         if(matrix[row][col] == 1)
         {
           int st = maxconnected(matrix, row, col, x, y);

           // cout << st << endl;
           mx = max(mx, st);

         }


       }
   }

   return mx;
}

int main()
{
    int matrix[6][7] = {
       {0, 0 , 0, 1, 1, 0, 0 },
       {0, 1 , 0, 0, 1, 1, 0 },
       {1, 1 , 0, 1, 0, 0, 1 },
       {0, 0 , 0, 0, 0, 1, 0 },
       {1, 1 , 0, 0, 0, 0, 0 },
       {0, 0 , 0, 1, 0, 0, 0 },
    };

    int x = 6, y = 7;

    //cin >> x >> y;

    /*for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            cin >> matrix[i][j];
        }
    }*/

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }



    int ans =  getmaxconnectcell(matrix, x, y);
    cout << ans << endl;
}
