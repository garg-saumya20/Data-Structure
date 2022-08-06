#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &A, int N, int M, int mid)
{
    int sum = 0;
    int count = 1;
    for (int i = 0; i < N; i++)
    {

        if (A[i] + sum <= mid)
        {
            sum += A[i];
        }
        else
        {
            count++;
            sum = A[i];
            if (count > M || A[i] > mid)
            {
                return false;
            }
        }
    }
    return true;
}
int Solution::solve(vector<int> &A, int B)
{

    int low = 0;
    int high = 0;
    int ans = -1;
    int N = A.size();
    for (int i = 0; i < N; i++)
    {
        high = high + A[i];
    }

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (isPossible(A, N, B, mid))
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
