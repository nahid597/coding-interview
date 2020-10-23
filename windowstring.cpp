#include<bits/stdc++.h>

using namespace std;

bool checkwindow(string s, string t, int start, int en)
{
    int n = t.size();

    int x[1000];
    memset(x, 0, sizeof(x));

    int y[1000];
    memset(y, 0, sizeof(y));

    ///cout << s << " " << t << endl;

    //cout <<"sdf" << y[100 ] << endl;

    bool flag = false;

    for(int i = 0; i < n; i++)
    {
        x[t[i]]++;
    }


    for(int i = start; i <= en; i++)
    {
       y[s[i]]++;
    }

    for(int i = 0; i < 156; i++)
    {

      if(y[i] >= x[i])
      {
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

string windowString(string s,string t)
{
    int start = 0, End = 0;

    bool flag = false;

     while(End < s.size())
     {
        if(!flag)
        {
           End++;
           flag = checkwindow(s,t,start, End);
        }
        else
        {
           //cout << "nahid" << endl;
            start++;
            flag = checkwindow(s,t,start, End);
            if(!flag)
            start--;
        }
     }

     string ans = "";

     for(int i = start; i < End; i++)
     {
        ans += s[i];
     }

    return ans;
}

int main()
{
   string s,t;

   //cin >> s;
   //cin >> t;
   s = "ADOBECODEBANC";
   t = "ABC";

  string ans = windowString(s,t);

  cout << ans << endl;

  /*string s1 = "ABCDA";
  string t1 = "BAC";

  bool ans = checkwindow(s1,t1,0,s1.size());

  cout << ans << endl;*/


    return 0;
}
