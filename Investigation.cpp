#include <bits/stdc++.h>

using namespace std;
const int mod = (1e9 + 7);
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, long long>>> adj(n + 1);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<long long> vals(n + 1, INT64_MAX);
    vector<long long> cnt(n + 1, 0);
    vector<int> mn(n + 1);
    vector<int> mx(n + 1);
    vector<bool> vis(n + 1, false);
    vals[1] = 0;
    cnt[1] = 1;
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 1});
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        if (vis[node.second])
            continue;
        vis[node.second] = true;
        for (auto child : adj[node.second])
        {
            if (vals[node.second] < INT64_MAX and vals[child.first] > vals[node.second] + child.second)
            {
                vals[child.first] = vals[node.second] + child.second;
                mn[child.first] = mn[node.second] + 1;
                mx[child.first] = mx[node.second] + 1;
                cnt[child.first] = cnt[node.second];
                pq.push({vals[child.first], child.first});
            }
            else if (vals[child.first] == vals[node.second] + child.second)
            {
                (cnt[child.first] += cnt[node.second]) %= mod;
                mn[child.first] = min(mn[child.first], mn[node.second] + 1);
                mx[child.first] = max(mx[node.second] + 1, mx[child.first]);
            }
        }
    }
    cout << vals[n] << ' ' << cnt[n] << ' ' << mn[n] << ' ' << mx[n] << endl;
}