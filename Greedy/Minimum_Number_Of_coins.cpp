#include <bits/stdc++.h>
#include <stack>
using namespace std;

vector<int> minPartition(int N)
{

    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 2000};
    vector<int> v;
    for (int i = 9; i >= 0; i--)
    {
        if (coins[i] <= N)
        {
            int n = N / coins[i];
            N -= n * coins[i];
            while (n)
            {
                v.push_back(coins[i]);
                n--;
            }
        }
    }
    return v;
}