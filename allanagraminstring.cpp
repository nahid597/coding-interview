#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s, p;

    cin >> s >> p;

    sort(p.begin(), p.end());

   // cout << s1 << endl << s2 << endl;

   string st = s;


        int flag = 1, cnt = 0;

        int sp = p.size();

        for(int i = 0; i <s.size() -sp + 1; i++)
        {
            cnt = 0;

            s = st;

            sort(s.begin()+i, s.begin() + i + sp);

            cout << s << endl;

            for(int j = 0; j < p.size(); j++)
            {
               if(s[j+i] == p[j])
               {
                   cnt++;
               }
            }

            if(cnt == sp)
            {
               cout << i <<endl;
            }
        }



    return 0;
}

