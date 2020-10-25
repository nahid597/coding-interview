#include<iostream>

using namespace std;

void Merge(int arr[], int l, int r)
{
    int mid = (l + r) / 2;

    int la = mid - l + 1 ;
    int ra =  r - mid;

    int i , j , k;

    int left[la+1], right[ra+1];

    for( i = 0; i < la; i++)
    {
        left[i] = arr[i+l];
    }

    for( i = 0; i < ra; i++)
    {
        right[i] = arr[i+mid+1];
    }

    i = 0;
    j = 0;
    k = l;

    while(i < la && j < ra)
    {
        if(left[i] <= right[j])
        {
            arr[k++] = left[i++];
        }
        else
        {
            arr[k++] = right[j++];
        }
    }

    while(i < la)
    {
      arr[k++] = left[i++];
    }

    while(j < ra)
    {
      arr[k++] = right[j++];
    }
}

void merseSort(int arr[], int l , int r)
{
    if(l < r)
    {
        int mid = (l+r) / 2;
        cout << mid << endl;

        merseSort(arr, l, mid);
        merseSort(arr, mid+1, r);
        Merge(arr, l , r);
    }
}

int main()
{
   int n;

   cin >> n;

   int *arg = (int*) malloc(n*sizeof(int));

   for(int i = 0; i < n; i++)
   {
      cin >> arg[i];
   }

    merseSort(arg, 0, n-1);

    for(int i = 0; i < n; i++)
   {
      cout << arg[i] << endl;
   }



    return 0;
}

