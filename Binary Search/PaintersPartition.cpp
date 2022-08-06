#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &arr, int n, int k, int mid)
{
    int painter = 1;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] + sum <= mid)
        {
            sum += arr[i];
        }
        else
        {
            painter++;
            sum = arr[i];
            if (painter > k || arr[i] > mid)
            {
                return false;
            }
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k)
{

    int low = 0;
    int high = 0;
    long long ans = -1;
  
    int n = boards.size();

    for (int i = 0; i < n; i++)
    {

        high = high + boards[i];
    }

   
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(boards, n, k, mid))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
