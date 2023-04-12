#include <bits/stdc++.h>
#define inf 1e18
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n + 1);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    vector<long long> cost(n + 1, inf);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0ll, 1});
    cost[1] = 0;
    vector<bool> vis(n + 1, false);
    while (!pq.empty())
    {
        auto g = pq.top();
        pq.pop();
        if (vis[g.second] == true)
            continue;
        vis[g.second] = true;
        for (auto child : adj[g.second])
        {
            if (0ll + g.first + child.second < 0ll + cost[child.first])
            {
                cost[child.first] = g.first + child.second;
                pq.push({cost[child.first], child.first});
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << cost[i] << ' ';
}