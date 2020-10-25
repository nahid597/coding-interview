#include<iostream>

using namespace std;

int main()
{
   int n;

   cin >> n;

   int *arg = (int*) malloc(n*sizeof(int));

   for(int i = 0; i < n; i++)
   {
      cin >> arg[i];
   }

   for(int i = 0; i < n; i++)
   {
     for(int j = 0; j < n-i-1; j++)
     {
        if(arg[j] >= arg[j+1])
        {
            int temp = arg[j];
            arg[j] = arg[j+1];
            arg[j+1] = temp;
        }
     }
   }

    for(int i = 0; i < n; i++)
   {
      cout << arg[i] << endl;
   }



    return 0;
}
