#include<bits/stdc++.h>

using namespace std;

bool hopper(int tower[],int index, int n, int h)
{

    int height = tower[index];

    //h += height;

    cout << index << endl;
    if(index >= n )
      return true;
    if(height == 0)
      return false;

    for(int i = 1; i <= height; i++)
    {
         if(hopper(tower, index + i, n,h))
            return true;
        //return ans;
    }
    return false;
}

int main()
{
    int tower[10] ;

    int n;

    cin >> n;

    for(int i = 0; i < n;i++)
    {
        cin >> tower[i];
    }

     //int sz = sizeof(tower) / sizeof(tower[0]);

    //cout << tower[0] << endl;
    int p = hopper(tower,0,n,0);
    cout << p << endl;

   if(p){
       cout << "tower pass" << endl;
   }
   else
   cout << "tower not pass" << endl;

    return 0;
}
