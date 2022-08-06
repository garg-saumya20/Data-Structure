#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> calculateSpan(int price[], int n)
{
    // Your code
    vector<int> v;
    stack<pair<int, int>> s;
    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            v.push_back(-1);
        }
        else if (s.size() > 0 && s.top().first > price[i])
        {
            v.push_back(s.top().second);
        }
        else if (s.size() > 0 && s.top().first <= price[i])
        {
            while (s.size() > 0 && s.top().first <= price[i])
            {
                s.pop();
            }
            if (s.size() == 0)
            {
                v.push_back(-1);
            }
            else
            
            {
                v.push_back(s.top().second);
            }
        }
        s.push({price[i], i});
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = i - v[i];
    }
    return v;
}

//TC O(N)
//SC O(N)