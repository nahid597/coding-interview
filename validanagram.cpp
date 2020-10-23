#include<bits/stdc++.h>

using namespace std;

struct st{
   char c;
   int a;
};

int main()
{
    string s1, s2;

    int x[1000] = {0}, y[1000] = {0};

    cin >> s1 >> s2;

    st p[100];

   // cout << s1 << endl << s2 << endl;

   if(s1.size() != s2.size())
     cout << "not anagram" << endl;

    else
    {
        for(int i = 0; i <s1.size(); i++)
        {
            x[s1[i]]++;
        }

        for(int i = 0; i <s2.size(); i++)
        {
            y[s2[i]]++;
        }


        int flag = 1;

        for(int i = 0; i < 256; i++)
        {
           cout << x[i] << " " << y[i] << endl;
            if(x[i] != y[i])
            {
                flag = 0;
                break;
            }
        }

        if(flag)
          cout << "valid anagram" << endl;
        else
           cout << "invalid anagram" << endl;
    }



    return 0;
}
