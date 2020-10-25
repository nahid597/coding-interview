#include<bits/stdc++.h>

using namespace std;

int main()
{
    stack<char>st;

    string s;
    int flag = 0;

    getline(cin, s);

    //cout << s << endl;

    for(int i = 0; i < s.size(); i++)
    {
       //cout << s[i] <<endl;
        if(s[i] == '(' || s[i] == '{'|| s[i] == '[')
        {
            st.push(s[i]);
        }

        else{

        cout << s[i] << " = " << st.top() << endl;

             if(s[i] == ')')
            {

                if(st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    flag = 0;
                    break;
                }
            }

            else if(s[i] == '}')
            {
                if(st.top() == '{')
                {
                    st.pop();
                }
                else
                {
                    flag = 0;
                    break;
                }
            }

            else if(s[i] == ']')
            {
                if(st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    flag = 0;
                    break;
                }
            }
        }

    }

    //cout << st.empty() << endl;

    if(st.empty())
      flag = 1;

    if(flag)
        cout << "Balanced parentechis" << endl;
    else
       cout << "Not Balanced" << endl;

    return 0;
}
