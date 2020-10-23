#include<bits/stdc++.h>

using namespace std;

string divided(string s, int div)
{
    int idx = 0;

    int temp = 0;

    /// 123456
    /// 37

    while(temp < div)
    {
       temp = temp * 10 + s[idx++] - '0';
    }

    cout << temp << " " << idx << endl;

    string ans;

    while(s.size() >= idx)
    {
        ans += temp / div + '0';

        temp = (temp % div) * 10 + (s[idx++] - '0');
    }

    cout << ans <<endl;

    return "nahid";
}

int main()
{
    string s;

    cin >> s;

    int n;

    cin >> n;

    string ans = divided(s, n);

    cout << ans << endl;

    return 0;
}
