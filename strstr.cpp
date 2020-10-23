#include<bits/stdc++.h>

using namespace std;

vector<int> icp(string text)
{
    vector<int>ip(text.length());

    int i = 0, index = 0;

    for(int i = 1; i < text.size(); )
    {
        if(text[i] == text[index])
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
               ip[i] = 0;
               i++;
           }
        }
    }

    return ip;
}

bool kmp(string text, string pattern)
{
    vector<int> ip = icp(pattern);
    bool flag = false;
    int index = 0;

    for(int i = 0; i < text.size(); )
    {
        if(text[i] == pattern[index])
        {
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

        if(index == pattern.length())
        {
            flag = true;
            break;
        }
    }

    return flag;
}

int main()
{
    string text, pattern;
    getline(cin, text);

    getline(cin , pattern);

    bool s = kmp(text, pattern);
    cout << s << endl;
    return 0;
}
