#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &A, int B, int mid)
{

    long int sum = 0;

    for (int i = 0; i < A.size(); i++)
    {

        if (A[i] > mid)
        {

            sum = sum + (A[i] - mid);
        }
    }

    if (sum < B)
    {

        return false;
    }

    return true;
}

int solve(vector<int> &A, int B)
{

    sort(A.begin(), A.end());

    int s = 0;

    int e = A[A.size() - 1];

    int mid = s + (e - s) / 2;

    int ans = 0;

    while (s <= e)
    {

        if (isPossible(A, B, mid))
        {

            ans = mid;

            s = mid + 1;
        }

        else
        {

            e = mid - 1;
        }

        mid = s + (e - s) / 2;
    }

    return ans;
}
