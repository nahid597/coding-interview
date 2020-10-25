#include<bits/stdc++.h>

using namespace std;

struct student {
    string name;
    int mark;
};

bool compair(student a, student b)
{
    if(a.mark == b.mark)
        return a.name < b.name;
    return a.mark < b.mark;
}

int main()
{
    student st[10];

    int m, n;
    string s;

    cout << "Enter number of students" << endl;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> s;
        st[i].name = s;
        cin >> m;
        st[i].mark = m;
    }


    sort(st, st + n , compair);

    for(int i = 0; i < n; i++)
    {
        cout << st[i].name << " = " << st[i].mark << endl;
    }




    return 0;
}
