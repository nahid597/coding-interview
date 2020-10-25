#include<bits/stdc++.h>

using namespace std;

void digit(int a, string s)
{

    if(a == 0)
    {
        reverse(s.begin(), s.end());
        for(int i = 0; i < s.size(); i++)
        {
            cout << s[i] << " ";
        }
        return;
    }

   int p = a % 10;
   //cout << p << " ";
   s += 48 + p;

   a = a / 10;
   digit(a, s);
}

int main()
{
    int a , b;

    cin >> a;

    digit(a, "");

    return 0;
}

