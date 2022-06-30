#include <iostream>
using namespace std;

 bool isMaxHeap(int a[], int n)
    {
        // Your code goes here
        int N=n/2;
        for(int i=N-1;i>=0;i--)
        {
            int largest = i;
        int left = 2 * i+1;
        int right = 2 * i + 2;
        if (left < n && a[largest] < a[left])
        {
            return false;
        }
        if (right < n && a[largest] < a[right])
        {
             return false;
        }
        }
        return true;
    }