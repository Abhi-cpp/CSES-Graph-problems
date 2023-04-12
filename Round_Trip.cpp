#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
bool iscycle = false;
vector<int> cycle;
vector<int> vis;

void dfs(int node, int parents = 0)
{
    if (vis[node] != -1 or iscycle)
        return;
    vis[node] = parents;
    for (auto child : adj[node])
    {
        if (child == parents)
            continue;
        else if (vis[child] != -1)
        {
            iscycle = true;
            cycle.push_back(child);
            auto tmp = node;
            while (tmp != child)
            {
                cycle.push_back(tmp);
                tmp = vis[tmp];
            }
            cycle.push_back(child);
        }
        else
            dfs(child, node);
        if (iscycle)
            return;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vis.resize(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == -1 and !iscycle)
        {
            dfs(i);
        }
    }
    if (iscycle)
    {
        cout << cycle.size() << endl;
        for (auto child : cycle)
            cout << child << ' ';
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE";
}