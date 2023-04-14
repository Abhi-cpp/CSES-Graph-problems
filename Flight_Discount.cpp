#include <bits/stdc++.h>

using namespace std;
void dijk(vector<vector<pair<int, long long>>> &adj, int node, vector<long long> &vis)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, node});
    vector<bool> done(vis.size(), false);
    vis[node] = 0;
    while (!pq.empty())
    {
        auto t = pq.top();
        pq.pop();
        if (done[t.second])
            continue;
        done[t.second] = true;
        for (auto child : adj[t.second])
        {
            if (vis[child.first] > vis[t.second] + child.second)
            {
                vis[child.first] = vis[t.second] + child.second;
                pq.push({vis[child.first], child.first});
            }
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj1(n + 1), adj2(n + 1);
    vector<vector<int>> edg;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj1[a].push_back({b, c});
        adj2[b].push_back({a, c});
        edg.push_back({a, b, c});
    }
    vector<long long> vis1(n + 1, 1e16), vis2(n + 1, 1e16);
    dijk(adj1, 1, vis1);
    dijk(adj2, n, vis2);
    long long ans = INT64_MAX;
    for (auto x : edg)
    {
        long long tmp = x[2] / 2 + vis1[x[0]] + vis2[x[1]];
        ans = min(ans, tmp);
    }
    cout << ans << endl;
}