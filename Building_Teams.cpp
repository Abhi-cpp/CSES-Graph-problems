#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> adj;
vector<int> vis;
bool flag = true;

void dfs(int node)
{
    for (auto child : adj[node])
    {
        if (vis[child] == -1)
        {
            vis[child] = vis[node] ^ 1;
            dfs(child);
        }
        else if (vis[child] == vis[node])
            flag = false;
    }
}

int main()
{
    int n, q;
    cin >> n >> q;
    adj.resize(n + 1);
    vis.resize(n + 1, -1);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == -1)
        {
            vis[i] = 0;
            dfs(i);
        }
    }
    if (!flag)
    {
        cout << "IMPOSSIBLE";
        exit(0);
    }
    for (int i = 1; i <= n; i++)
        cout << vis[i] + 1 << ' ';
}