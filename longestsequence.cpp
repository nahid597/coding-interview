#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    cin >> s;

    int cnt =  1, st = 0;
    char ch;

    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == s[i+1])
        {
            cnt++;
        }
        else
        {
            cnt = 1;
        }

        if(st < cnt)
        {
            st = cnt;
            ch = s[i];
        }
    }

    cout << ch << " " << st << endl;

    return 0;
}
