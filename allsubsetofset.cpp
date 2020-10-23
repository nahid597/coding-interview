#include<bits/stdc++.h>

using namespace std;

void printPowerSet(char set[], int n)
{
    int pn = pow(2, n);

     for(int i = 0; i < pn; i++)
     {
        for(int j = 0; j < n; j++)
        {
            if(i & (1 << j))
            {
                cout << set[j]  << " ";
            }
        }

        cout << endl;
     }
}


int main()
{
    char set[] = {'a','b','c'};
    printPowerSet(set, 3);

    return 0;
}
