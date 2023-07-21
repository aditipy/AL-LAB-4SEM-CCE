// if directed
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool iscycle(int src, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &stack)
{
    stack[src] = true;
    if(!vis[src])
    {
        vis[src]=true;
    
        for (auto it : adj[src])
        {
            
            if (!vis[it] and iscycle(it, adj, vis, stack))
            {
                return true;
            }
            if(stack[it])
                return true;
        }
        
    }
    stack[src]=false;
        
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
        // adj[v].push_back(u);
    }
    bool cycle = false;
    vector<int> stack(n,0); 
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i] and iscycle(i, adj, vis, stack))
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

