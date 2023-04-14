#include <bits/stdc++.h>
const int mod = (1e9 + 7);
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    vector<int> top;
    queue<int> q;
    vector<long> vals(n + 1, 0);
    for (int i = 1; i <= n; i++)
        if (indegree[i] == 0)
            q.push(i);
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        top.push_back(node);
        for (auto child : adj[node])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }
    vals[1] = 1;
    for (auto x : top)
    {
        for (auto node : adj[x])
        {
            vals[node] += vals[x];
            vals[node] %= mod;
        }
    }
    cout << vals[n] << endl;
}