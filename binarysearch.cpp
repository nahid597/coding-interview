#include<bits/stdc++.h>

using namespace std;

int binarysearch(int arr[], int l, int r, int key)
{
    if(l <= r)
    {
      cout<< l<< " " << r << endl;
        int mid = (l+r) / 2;

        if(arr[mid] == key)
        {
           return mid;
        }

        if(key < arr[mid])
        {
            return binarysearch(arr, l, mid-1, key);
        }
        else
        {
            return binarysearch(arr, mid + 1, r, key);
        }

    }

    return -1;
}

int main()
{

   int n;

   cin >> n;

   int arr[n+1];

   for(int i = 0; i < n; i++)
   {
      cin >> arr[i];
   }

   sort(arr, arr+n);

   int se;
   cout << "which element u want to search ";
   cin >> se;

   int ans = binarysearch(arr, 0, n-1, se);

   cout << ans << endl;

    return 0;
}
