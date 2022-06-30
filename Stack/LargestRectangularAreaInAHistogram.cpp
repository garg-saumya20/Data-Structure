#include <iostream>
using namespace std;
#include <vector>
#include <stack>
vector<int> NSL(vector<int> h)
{
    vector<int> left;
    stack<pair<int, int>> st;
    int pseudo = -1;
    for (int i = 0; i < h.size(); i++)
    {
        if (st.empty())
            left.push_back(pseudo);

        else if (st.size() > 0 && st.top().first < h[i])
            left.push_back(st.top().second);

        else if (st.size() > 0 && st.top().first >= h[i])
        {
            while (st.size() > 0 && st.top().first >= h[i])
                st.pop();
            if (st.empty())
                left.push_back(pseudo);
            else
                left.push_back(st.top().second);
        }
        st.push({h[i], i});
    }
    return left;
}

// next smaller to right traverse --> from right
// here we will assume that one building is after lastmost index of 0 height
vector<int> NSR(vector<int> h)
{
    vector<int> right;
    stack<pair<int, int>> st;
    int pseudo = h.size();
    for (int i = h.size() - 1; i >= 0; i--)
    {
        if (st.empty())
            right.push_back(pseudo);
        else if (st.size() > 0 && st.top().first < h[i])
            right.push_back(st.top().second);
        else if (st.size() > 0 && st.top().first >= h[i])
        {
            while (st.size() > 0 && st.top().first >= h[i])
                st.pop();
            if (st.empty())
                right.push_back(pseudo);
            else
                right.push_back(st.top().second);
        }
        st.push({h[i], i});
    }
    return right;
}

int largestRectangleArea(vector<int> &heights)
{
    vector<int> left = NSL(heights);
    vector<int> right = NSR(heights);
    vector<int> width;
    reverse(right.begin(), right.end()); // reversing to get the correct order of next smaller to right

    int maxarea = -1;
    for (int i = 0; i < heights.size(); i++)
    {
        int width = right[i] - left[i] - 1;
        maxarea = max(maxarea, width * heights[i]);
    }
    return maxarea;
}