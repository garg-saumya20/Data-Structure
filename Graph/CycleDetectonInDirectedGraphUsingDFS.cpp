#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adj, vector<pair<int, int>> edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }
}

bool isCyclicDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited, unordered_map<int, list<int>> &adj)
{

    visited[node] = 1;
    dfsVisited[node] = 1;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            bool cycleDetected = isCyclicDFS(neighbour, visited, dfsVisited, adj);
            if (cycleDetected)
            {
                return true;
            }
        }
        else if (dfsVisited[neighbour])
        {
            // cycle is present
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

int cycleDetection(vector<pair<int, int>> edges, int n)
{
    // prepare adjacency list
    unordered_map<int, list<int>> adj;
    prepareAdjList(adj, edges);

    // Call DFS for all components
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsVisited;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            bool ans = isCyclicDFS(i, visited, dfsVisited, adj);
            if (ans == 1)
            {
                return 1;
            }
        }
    }
    return 0;
}