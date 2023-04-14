#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<int, long long>>> adj(n + 1);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});
    vector<vector<long long>> vis(n + 1, vector<long long>(k, 1e16));
    vector<long long> ans;
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        if (vis[node.second][k - 1] < node.first)
            continue;
        for (auto child : adj[node.second])
        {
            if (vis[child.first][k - 1] > node.first + child.second)
            {
                vis[child.first][k - 1] = node.first + child.second;
                pq.push({vis[child.first][k - 1], child.first});
                sort(vis[child.first].begin(), vis[child.first].end());
            }
        }
    }
    for (auto x : vis[n])
        cout << x << ' ';
}