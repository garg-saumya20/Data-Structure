#include <iostream>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }
    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[index], arr[parent]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete from heap";
            return;
        }
        // step 1: put last element into first index
        arr[1] = arr[size];

        // step 2; remove last element
        size--;

        // step 3: Take root node to its correct position

        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[leftIndex] > arr[i])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex < size && arr[rightIndex] > arr[i])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }

    void heapify(int arr[], int n, int i)
    {
        int largest = i;
        int left = 2 * i;
        int right = 2 * i + 1;
        if (left < n && arr[largest] < arr[left])
        {
            largest = left;
        }
        if (right < n && arr[largest] < arr[right])
        {
            largest = right;
        }e
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deleteFromHeap();
    h.print();
    // int arr[6] = {-1, 54, 53, 55, 52, 50};
       int arr[7] = {-1,3,9,2,1,4,5};
    int n = 6;
    // for (int i = n / 2; i > 0; i--)
    // {
    //     h.heapify(arr, n, i);
    // }
    h.heapify(arr,n,3);
     cout << "After heapify,array elements are:" << endl;
     for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
     h.heapify(arr,n,2);
      cout << "After heapify,array elements are:" << endl;
      for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
      h.heapify(arr,n,1);
    cout << "After heapify,array elements are:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;
     for (int i = n / 2; i > 0; i--)
     {
         h.heapify(arr, n, i);
     }
     cout << "After heapify,array elements are:" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}