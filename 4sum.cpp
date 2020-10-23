#include<bits/stdc++.h>

using namespace std;

struct st{
    int first;
    int sec;
    int sum;
};

bool compare(st a, st b)
{
    return a.sum < b.sum;
}

bool noCommon(st a, st b)
{
    if(a.first == b.first
      ||a.first == b.sec
      ||a.sec == b.first
      ||a.sec == b.sec )
      {
        return false;
    }
    return true;
}

void foursum(int arg[], int n, int t)
{
    st aug[1000];

    int k = 0;

    for(int i = 0; i < n; i++)
    {
       for(int j = i + 1; j < n; j++)
       {
           aug[k].sum = arg[i] + arg[j];
           aug[k].first = i;
           aug[k].sec = j;
           k++;
       }
    }

    sort(aug, aug + k, compare);

    int i = 0 , j = k -1;

    while(i < j)
    {
        int sum = aug[i].sum + aug[j].sum;

        //cout << sum <<endl;

        if(sum == t && noCommon(aug[i], aug[j]))
        {
           cout << arg[aug[i].first] << " " << arg[aug[i].sec] << endl;
           cout << arg[aug[j].first] << " " << arg[aug[j].sec] << endl;
           return;
        }

        else if(sum < t)
        {
            i++;
        }
        else
        {
            j--;
        }
    }

   /* for(int i = 0; i < k; i++)
    {
        cout << aug[i].sum << " " << aug[i].first << " , " << aug[i].sec << endl;
    }*/

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

    foursum(x,n,t);

    return 0;
}
