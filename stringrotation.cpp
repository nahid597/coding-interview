#include<bits/stdc++.h>

using namespace std;

bool stringRotation(string s1, string s2)
{
    int sz1 = s1.size();
    int sz2 = s2.length();

    if(sz1 != sz2)
    return false;

    int start = 0, end = 0, index = 0;

    for(int i = 0; i < sz1; i++)
    {
        if(s1[i] == s2[index])
        {
            index++;
        }
    }

    //end = index;

    //index = 0;
    int reaming = sz1 - index;
    bool flag = false;

    for(int i = 0; i < reaming; i++)
    {
       if(s1[i] == s2[index])
       {
            index++;
            flag = true;
       }
       else
       {
           flag = false;
           break;
       }
    }

    return flag;
}

int main()
{
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

   bool p = stringRotation(s1,s2);
   cout << p <<endl;
    return 0;
}
