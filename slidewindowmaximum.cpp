#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n, w;
    cin >> n ;

    int *x = new int[100];
    int *y = (int*) malloc(n*sizeof(int));

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    cout << "Enter window length" << endl;
    cin >> w;

    int mx = 0;

    for(int i = 0; i < w; i++)
    {
        mx = max(x[i] , mx);
    }

    int k = 0;

    y[k++] = mx;

    for(int i = 1; i < n -w + 1; i++)
    {
        cout << x[i+w -1 ] << " " << mx << " " << x[i-1] << endl;
        if(x[i+w-1] < mx && x[i-1] != mx)
        {
            y[k++] = mx;
        }
        else
        {
            if(x[i-1] != mx)
            {
                y[k++] = x[i+w-1];
            }
            else
            {
               mx = x[i];
               for(int j = 0; j < w; j++)
                {
                    mx = max(x[j+i] , mx);
                }

                y[k++] = mx;
            }
        }
    }

    for(int i = 0; i < k; i++)
    {
        cout << y[i]<< endl;
    }



    return 0;
}
