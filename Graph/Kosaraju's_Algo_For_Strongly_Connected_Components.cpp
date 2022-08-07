#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

void prepareAdjList(unordered_map<int, list<int>> &adj, vector<vector<int>> &edges)
{
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void dfs(int node, unordered_map<int, bool> &visited, stack<int> &st, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            dfs(nbr, visited, st, adj);
        }
    }
    // topo logic
    st.push(node);
}
void revdfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj)
{
    visited[node] = true;
    for (auto nbr : adj[node])
    {
        if (!visited[nbr])
        {
            revdfs(nbr, visited, adj);
        }
    }
}
int SCC(int v, vector<vector<int>> &edges)
{
    // prepare adjacency list
    unordered_map<int, list<int>> adj;
    prepareAdjList(adj, edges);

    // topo sort
    stack<int> st;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, visited, st, adj);
        }
    }

    // create a transpose of a graph

    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < v; i++)
    {
        visited[i] = 0;
        for (auto nbr : adj[i])
        {
            transpose[nbr].push_back(i);
        }
    }

    // dfs call suing above ordering
    int count = 0;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (!visited[top])
        {
            count++;
            revdfs(top, visited, transpose);
        }
    }
    return count;
}