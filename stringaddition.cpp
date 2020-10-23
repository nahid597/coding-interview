#include<bits/stdc++.h>

using namespace std;

string addition(string s1, string s2)
{
    int sz1 = s1.size();
    int sz2 = s2.size();

    int mx = max(sz1,sz2);

    //cout << mx << endl;

    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    for(int i = sz1; i < mx; i++)
    {
        s1 += 48;
    }

    for(int i = sz2; i < mx; i++)
    {
        s2 += 48;
    }

   //cout << s1 << endl << s2 << endl;

   string ans;

   /// 34893
   /// 98000

   int carry = 0;

   for(int i = 0; i < mx; i++)
   {
       int digit1 = s1[i] - 48;
       int digit2 = s2[i] - 48;

       int sum = digit1 + digit2 + carry;

       carry = sum / 10;
       ans += sum % 10 + 48;
   }

   if(carry != 0)
      ans += carry + 48;

   reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{

    string s1, s2;

    cin >> s1 >> s2;

    string ans = addition(s1,s2);
    cout << ans << endl;
    return 0;
}
