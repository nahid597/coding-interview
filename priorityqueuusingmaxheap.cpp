#include<bits/stdc++.h>

using namespace std;

int left(int i)
{
 return  2 *i;
}

int right(int i)
{
    return 2 * i + 1;
}

int parent(int i)
{
    return i / 2;
}

void max_heapify(int heap[], int heap_size, int i)
{

    int l = left(i);
    int r = right(i);

    int largest;

    if(l <= heap_size && heap[l] > heap[i])
    {
        largest = l;
    }
    else
    {
        largest = i;
    }

    if(r <= heap_size && heap[r] > heap[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        int temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        max_heapify(heap, heap_size, largest);
    }

}

void buildHeap(int heap[], int heap_size)
{
    for(int i =  heap_size / 2; i >= 1; i--)
    {
        max_heapify(heap, heap_size, i);
    }
}

int extract_max(int heap[], int heap_size)
{
    int mx = heap[1];

    heap[1] = heap[heap_size];

    heap_size--;
    max_heapify(heap, heap_size, 1);

    return mx;
}

int insertNode(int heap[], int heap_size, int node)
{
    heap_size++;

    heap[heap_size] = node;

    int i = heap_size;

    while(i > 1 && heap[i] > heap[parent(i)])
    {
        int p = parent(i);

        int temp = heap[i];
        heap[i] = heap[p];
        heap[p] = temp;

        i = p;
    }

    return heap_size;
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

  // for(int i = 1; i <= n; i++)
   //{
    //  cout << heap[i] << endl;
  // }

  int m = extract_max(heap, n);
  cout  <<"before insert \n"<< m << " \n ater inset" << endl;

  int sz = insertNode(heap, n, 60);

   m = extract_max(heap, sz);
  cout << m << endl;



    return 0;
}

