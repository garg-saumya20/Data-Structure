#include <iostream>
using namespace std;
#include <queue>
#include <vector>

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dis(V, INT_MAX);
        dis[S] = 0;
        pq.push(make_pair(0, S));
        while (!pq.empty())
        {
            int weight = pq.top().first;
            int vertex = pq.top().second;
            pq.pop();
            for (auto it : adj[vertex])
            {
                int next_vertex = it[0];
                int next_weight = it[1];
                if (dis[next_vertex] > dis[vertex] + next_weight)
                {
                    dis[next_vertex] = dis[vertex] + next_weight;
                    pq.push(make_pair(dis[next_vertex], next_vertex));
                }
            }
        }
        return dis;
    }
};