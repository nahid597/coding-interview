#include<bits/stdc++.h>

using namespace std;

void kdifference(int x[], int n,int t){

    int i = 0, j = i + 1;

    while(i < n -1 && j < n)
    {
        int dif = x[j] - x[i];
        if(dif == t)
        {
            cout << x[i] << " " << x[j] << endl;
            break;
        }
        else if(dif < t)
        {
            j++;
        }
        else
        {
            i++;
        }
    }

}

int main()
{
    int n, t;
    cin >> n;

    int x[n+1];

    for(int i = 0; i < n; i++)
    {
        cin >> x[i];
    }

    cout << "enter target" << endl;
    cin >> t;

    kdifference(x,n,t);

    return 0;
}
