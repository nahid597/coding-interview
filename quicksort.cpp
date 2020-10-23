#include<iostream>

using namespace std;

int partation(int arg[], int l , int r)
{
    int pivot = arg[r];
    int pindex = l;

    for(int i = l; i < r; i++) {
        if(arg[i] <= pivot) {
          swap(arg[i], arg[pindex++]);
        }
    }

    swap(arg[pindex], arg[r]);

    return pindex;
}

void quickSort(int arg[], int l , int r)
{
    if(l < r)
    {
        int mid = partation(arg, l, r);
        quickSort(arg, l , mid-1);
        quickSort(arg, mid + 1, r);

    }
}

int main()
{
    //int *arg = (int*) malloc(100 * sizeof(int));

    int *arg = (int*) malloc(100*sizeof(int));

    int n;

    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arg[i];
    }

    quickSort(arg, 0, n-1);

     for(int i = 0; i < n; i++)
    {
        cout << arg[i] << " ";
    }



    return 0;
}



