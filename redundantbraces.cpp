#include<bits/stdc++.h>

using namespace std;

int main()
{
    string s;

    stack<char>st;

    cin >> s;

     bool flag = false;

    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == ')')
        {
            char top = st.top();
            st.pop();

            flag = true;

            while(top != '(')
            {
               if(top == '+' || top == '-' || top == '/' || top == '*')
               {
                    flag = false;
               }

               top = st.top();
               st.pop();
            }

            if(flag)
            {
              //cout << "true" << endl;
              break;
            }

        }
        else
        {
            st.push(s[i]);
        }
    }

    cout << flag << endl;

    return 0;
}
