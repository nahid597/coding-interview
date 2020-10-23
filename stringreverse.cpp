#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s, st;

    getline(cin, s);

    istringstream is(s);

    /*while(is >> st)
    {
        cout << st << endl;
    }*/

    /// hello world

    int start = 0, end = s.size();

    for(int i = s.size() -1; i >= 0; i--)
    {
        if(s[i] == ' ' || i == 0)
        {
            if(i == 0)
               i = i - 1;

            for(int j = i+1; j < end; j++)
            {
               cout << s[j];
            }
            cout << " ";
            end = i;
        }


    }




    return 0;
}
