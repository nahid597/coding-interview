#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    cin >> s;

    int flag = 0;

    for(int i = 0; i < s.size() -1; i++)
    {
        int n1 = s[i] - 48;
        int n2 = s[i+1] - 48;

       // cout << n1 << " " << n2 << endl;

       int df = n2 - n1;

       if(df == 1)
       {
          flag = 1;
       }
       else{
        flag = 0;
        break;
       }
    }

    if(flag)
      cout << "humble number"<< endl;
    else
       cout << "not humble number"<< endl;

    return 0;
}
