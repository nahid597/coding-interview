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

void max_heapify(int heap[], int heap_size, int i)
{
    int l = left(i);
    int r = right(i);
    int temp, largest = 0;

    if(l <= heap_size && heap[i] < heap[l] )
    {
        largest = l;
    }
    else{
        largest = i;
    }

    if(r <= heap_size && heap[r] > heap[largest])
    {
        largest = r;
    }

    if(i != largest)
    {
        temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        max_heapify(heap, heap_size, largest);
    }
}

void buildHeap(int heap[], int heap_size)
{
    for(int i = heap_size/2; i >= 1; i--)
    {
        max_heapify(heap, heap_size, i);
    }
}

int main()
{
    int n;

    cin >> n;

    int heap[n+1];

    for(int i = 1; i <= n; i++)
    {
        cin >> heap[i];
    }

    buildHeap(heap, n);

   for(int i = 1; i <= n; i++)
   {
      cout << heap[i] << endl;
   }

    return 0;
}
