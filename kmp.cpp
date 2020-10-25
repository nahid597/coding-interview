#include<bits/stdc++.h>

using namespace std;

vector<int>countLps(string pattern)
{
    vector<int> lps(pattern.length());

    int index = 0;
    //cout << pattern.length() << endl;

    for(int i = 1; i < pattern.length(); )
    {
        //cout << "nahid" << endl;
        if(pattern[i] == pattern[index])
        {
            lps[i] = index + 1;
            index++;
            i++;
        }
        else
        {
           if(index != 0)
           {
                index = lps[index-1];
           }
           else
           {
               lps[i] = 0;
               i++;
           }

        }
    }

    return lps;
}

int kmp(string text, string pattern)
{
    int index = 0;

    vector<int> lps = countLps(pattern);

    for(int i = 0; i < text.size();)
    {
        if(text[i] == pattern[index])
        {
            i++;
            index++;
        }

        else
        {
           if(index != 0) index = lps[index-1];

           else
           {
             i++;
           }
        }

        if(index == pattern.size())
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
   string text, pattern;

   cout << "Enter text ";
   getline(cin, text);

   cout << "Enter pattern ";
   getline(cin, pattern);

   int ans = kmp(text, pattern);
   if(ans)
     cout << "pattern match"<< endl;
   else
      cout << "pattern not match"<< endl;

    return 0;
}
