#include <bits/stdc++.h>

using namespace std;
vector<int> ans;
vector<int> vis;
vector<int> parents;
vector<vector<int>> adj;
bool cycle = false;

void dfs(int node)
{
    vis[node] = 1;
    for (auto child : adj[node])
    {
        if (vis[child] == 0)
        {
            parents[child] = node;
            dfs(child);
        }
        else if (vis[child] == 1)
        {
            parents[child] = node;
            cycle = true;
            ans.push_back(child);
            for (int k = node;; k = parents[k])
            {
                ans.push_back(k);
                if (k == child)
                    break;
            }
            cout << ans.size() << endl;
            reverse(ans.begin(), ans.end());
            for (auto x : ans)
                cout << x << ' ';
            exit(0);
        }
        else
        {
            continue;
        }
    }
    vis[node] = 2;
}

int main()
{
    int n, m;
    cin >> n >> m;
    parents.resize(n + 1);
    adj.resize(n + 1);
    vis.resize(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0 and !cycle)
        {
            parents[i] = i;
            dfs(i);
        }
    }
    cout << "IMPOSSIBLE";
}