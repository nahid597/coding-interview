#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s1, s2;

    getline(cin , s1);
    getline(cin, s2);

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    int sz1, sz2, mx = 0;

    sz1 = s1.length();
    sz2 = s2.length();

    mx = max(sz1, sz2);

    for(int i = sz1; i < mx; i++)
    {
       s1 += '0';
    }

    for(int i = sz2; i < mx; i++)
    {
       s2 += '0';
    }

    int c = 0;

    string ans = "";

    for(int i = 0; i < mx; i++)
    {
         int p1 = s1[i] - 48;
         int p2 = s2[i] - 48;

        int sum = (p1 + p2 + c);

        c = sum / 10;

        ans += (sum % 10) + 48;

    }

    reverse(ans.begin(), ans.end());

    cout << s1 << endl << s2 <<endl << "ans " << ans << endl;



    return 0;
}
