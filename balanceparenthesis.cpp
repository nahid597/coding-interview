#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack<char>st;

    string str;

    cin >> str;

    bool flag = true;

    for(int i = 0; i < str.size(); i++)
    {
        if(str[i] == '(' || str[i] == '{' || str[i] == '[')
        {
           st.push(str[i]);
        }
        else
        {
            //cout << str[i] << endl;
            char ch = st.top();
            st.pop();

            if(str[i] == ')')
            {
               if(ch != '(')
               {
                  flag = false;
                  break;
               }
            }
            else if(str[i] == '}')
            {
               if(ch != '{')
               {
                  flag = false;
                  break;
               }
            }

           else if(str[i] == ']')
            {
               if(ch != '[')
               {
                  flag = false;
                  break;
               }
            }

        }
    }

    cout << flag << endl;

    return 0;
}
