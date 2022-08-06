#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <stack>
#include <vector>
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

void topoSort(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            topoSort(neighbour, visited, s, adj);
        }
    }
    // imp
    s.push(node);
}
vector<int> topologicalSort(vector<pair<int, int>> edges, int v, int e)
{
    // create adjacency list
    unordered_map<int, list<int>> adj;
    prepareAdjList(adj, edges);

    // call dfs topological sort util function for all components

    unordered_map<int, bool> visited;
    //vector<bool> visited;
    stack<int> s;

    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topoSort(i, visited, s, adj);
        }
    }

    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}