#include<bits/stdc++.h>

using namespace std;

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

void max_heapify(int heap[], int heap_size, int index)
{
    int largest, l , r;

    l = left(index);
    r = right(index);

    if(l <= heap_size && heap[l] >= heap[index])
    {
        largest = l;
    }
    else
       largest = index;

    if(r <= heap_size && heap[r] >= heap[largest])
    largest = r;

    int temp;

    if(largest != index)
    {
       temp = heap[index];
       heap[index] = heap[largest];
       heap[largest] = temp;

       max_heapify(heap, heap_size, largest);
    }

}

void build_heap(int heap[], int heap_size)
{
    for(int i = heap_size / 2; i >= 1; i--)
    {
        max_heapify(heap, heap_size, i);
    }
}

void heap_sort(int heap[], int heap_size)
{
   int temp;
   build_heap(heap, heap_size);

   for(int i = heap_size; i > 1; i--)
   {
      temp = heap[1];
      heap[1] = heap[i];
      heap[i] = temp;

      heap_size--;

      max_heapify(heap, heap_size, 1);
   }

}

int main()
{

   int n;

   cin >> n;

   int heap[n+2];

   for(int i = 1; i <= n; i++)
   {
      cin >> heap[i];
   }

   build_heap(heap, n);

    for(int i = 1; i <= n; i++)
   {
      cout << heap[i] << endl;
   }

   cout << "agfter sorting " << endl;
   heap_sort(heap, n);

   for(int i = 1; i <= n; i++)
   {
      cout << heap[i] << endl;
   }


    return 0;
}


