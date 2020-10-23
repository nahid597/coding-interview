#include<bits/stdc++.h>

using namespace std;

double bs(int key, double l , double r)
{
    if(l <= r)
    {
        double mid = (l + r) / 2;

        double mul = mid * mid;

        if(mul == key || (abs(key - mul) < 0.0001))
        {
            return mid;
        }
        else if(mul < key){
            return bs(key, mid, r);
        }
        else
        {
            return bs(key, l, mid);
        }
    }

}

int main()
{
    int n;

    cin >> n;

    float s = sqrt(n);

    cout << s << endl;

    double b = bs(n , 0,n);
    cout << fixed <<setprecision(3) << b << endl;

    return 0;
}
