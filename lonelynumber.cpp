#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

   // int x[n+1];

    //dynamic array
   // int *x = (int*) malloc(n*sizeof(int));
     int *x = new int[10];


    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    int r = 0;

    for(int i = 0; i < n; i++)
    {
       r = r ^ x[i];
       cout << r << endl;
    }

    cout << "res " << r << endl;

    return 0;
}
