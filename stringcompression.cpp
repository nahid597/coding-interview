#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    getline(cin, s);

    sort(s.begin(), s.end());

    //cout << s << endl;

    int cnt = 1;

    for(int i = 0; i < s.length() -1; i++)
    {
        if(s[i] != s[i+1])
        {
            cout << s[i]<< cnt << endl;
            cnt = 1;
        }
        else
          cnt++;
    }

    cout << s[s.length() - 1] << cnt << endl;

    return 0;
}
