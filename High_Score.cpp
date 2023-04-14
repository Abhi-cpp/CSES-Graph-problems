#include <bits/stdc++.h>

using namespace std;
struct node
{
    int from, to;
    long long cost;
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> edges(m);
    for (auto &x : edges)
        cin >> x.from >> x.to >> x.cost;
    vector<long long> vis(n + 1, -1e16);
    vis[1] = 0;
    for (int i = 1; i < n; i++)
    {
        for (auto x : edges)
        {
            if (vis[x.from] == -1e16)
                continue;
            if (vis[x.to] < vis[x.from] + x.cost)
            {
                vis[x.to] = vis[x.from] + x.cost;
            }
        }
    }
    long long tmp = vis[n];
    for (int i = 1; i < n; i++)
    {
        for (auto x : edges)
        {

            if (vis[x.from] == -1e16)
                continue;
            if (vis[x.to] < vis[x.from] + x.cost)
            {
                vis[x.to] = 1e16;
            }
        }
    }
    if (tmp != vis[n])
        cout << "-1\n";
    else
        cout << vis[n];
}