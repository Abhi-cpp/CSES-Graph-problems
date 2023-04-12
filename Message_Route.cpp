#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> vis(n + 1, -1);
    vis[1] = 0;

    // bfs
    queue<int> q;
    q.push(1);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        for (auto child : adj[node])
        {
            if (vis[child] == -1)
            {
                vis[child] = node;
                q.push(child);
            }
        }
    }

    if (vis[n] == -1)
    {
        cout << "IMPOSSIBLE";
        exit(0);
    }

    vector<int> ans;
    int cur = n;
    while (cur != 0)
    {
        ans.push_back(cur);
        cur = vis[cur];
    }
    cout << ans.size() << endl;
    reverse(ans.begin(), ans.end());
    for(auto x:ans)
        cout << x << ' ';
}