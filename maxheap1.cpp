#include<bits/stdc++.h>

using namespace std;

class Heap {

   public:

    int left(int i)
    {
       return 2 * i;
    }

    int right(int i)
    {
        return 2 * i + 1;
    }

    int parrent(int i)
    {
        return i / 2;
    }

    void max_heapify(int heap[], int i, int heap_size)
    {
        int l = left(i);
        int r = right(i);

        int temp, largest;

        if(heap[i] < heap[l] && l <= heap_size)
        {
            largest = l;
        }
        else
        {
            largest = i;
        }

        if(heap[largest] < heap[r] && r <= heap_size)
        {
            largest = r;
        }

        if(largest != i)
        {
            temp = heap[i];
            heap[i] = heap[largest];
            heap[largest] = temp;

            max_heapify(heap, largest, heap_size);
        }


    }

    void buildHeap(int heap[], int heap_size)
    {
        for(int i = heap_size/ 2; i >= 1; i--)
        {
           max_heapify(heap, i, heap_size);
        }
    }
};

int main()
{
   Heap obj;

    int n;

   cin >> n;

   int heap[n+2];

   for(int i = 1; i <= n; i++)
   {
      cin >> heap[i];
   }

   obj.buildHeap(heap, n);

   for(int i = 1; i <= n; i++)
   {
      cout << heap[i] << endl;
   }

    return 0;
}
