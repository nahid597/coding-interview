#include<iostream>

using namespace std;

class permutation
{
    public:
       int n;
       int r;
       int st[1000];
       void permit(int n, int r)
       {
           st[0] = 1;
            for(int i = 1; i <= n; i++)
            {
               st[i] = st[i-1] * i;
            }
       }
};

int main()
{
    permutation obj;

    cin >> obj.n >> obj.r;


    obj.permit(obj.n, obj.r);

    int ans = obj.st[obj.n] / obj.st[obj.n-obj.r];

    cout << ans << endl;


}
