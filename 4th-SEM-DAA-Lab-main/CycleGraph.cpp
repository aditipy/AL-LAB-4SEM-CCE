// for undirected
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool iscycle(int src, vector<vector<int>> &adj, vector<bool> &vis, int parent)
{
    vis[src] = true;
    for (auto it : adj[src])
    {
        if (it != parent)
        {
            if (vis[it])
                return true;
            if (!vis[it] and iscycle(it, adj, vis, src))
            {
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    bool cycle = false;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] and iscycle(i, adj, vis, -1))
        {
            cycle = true;
        }
    }
    if (cycle)
        cout << "Cycle is present";
    else
        cout << "Cycle is not present";

    return 0;
}

// if directed
