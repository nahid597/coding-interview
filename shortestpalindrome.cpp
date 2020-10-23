#include<bits/stdc++.h>

using namespace std;

bool palindrome(string s)
{
    string rs = s;
    reverse(rs.begin(), rs.end());

    return rs == s;
}

vector<int> kmp(string s)
{
    vector<int>ip(s.length());

    int i = 0, index = 0;

    for(i = 1; i < s.length(); )
    {
        if(s[i] == s[index])
        {
            ip[i] = index + 1;
            i++;
            index++;
        }
        else
        {
            if(index != 0)
            {
                index = ip[index -1];
            }
            else
            {
               i++;
            }
        }
    }

    return ip;
}

string shortestplaindrome(string s)
{
    // check given string palinedrome or not
    if(palindrome(s))
    {
       return s;
    }

    string rs = s;

    reverse(rs.begin(), rs.end());

    string sts = s + rs;

   // cout << sts << endl;

    /// check kmp

    vector<int> ip = kmp(sts);

    int mx = 0;

    for(int i = 0; i < ip.size(); i++)
    {
     //  cout << ip[i] << endl;

       mx = max(mx, ip[i]);
    }

    //cout << "max" << mx <<endl;

    string ns;

    for(int i = 0; i < rs.size() - mx; i++)
    {
        ns += rs[i];
    }

    //cout << ns << endl;

    string ans;

    ans = ns + s;

    //cout << ans << endl;

    return ans;
}

int main()
{
    string s;

    cin >> s;

    string ans = shortestplaindrome(s);

    cout << ans << endl;

    cout << ans.size() - s.size() <<endl;


    return 0;
}
