#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s, p;

    cin >> s >> p;


   // cout << s1 << endl << s2 << endl;

        int flag = 1, cnt = 0, y[1000] = {0};

        int sp = p.size();

        for(int i = 0; i < sp; i++)
        {
           y[p[i]]++;
        }

        for(int i = 0; i <s.size() -sp + 1; i++)
        {
            flag = 1;
           int x[1000] = {0};
          // cout << x[97] << endl;
            for(int j = 0; j < sp; j++)
            {
              // cout << s[j+i];
               x[s[j+i]]++;
               //cout << x[s[j+i]] << endl;
            }
            //cout << endl;

            for(int k = 97; k < 125; k++)
            {
               //cout << x[k] << " " << y[k] << endl;
               if(x[k] != y[k])
               {
                   flag = 0;
                   break;
               }
            }

            if(flag)
            {
               cout << i << " , " << i + sp -1 << endl;
            }
        }



    return 0;
}


