#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<int> indegree(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    vector<int> top;
    queue<int> q;
    vector<int> parents(n + 1, 0);
    vector<int> vals(n + 1, 0);
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
        if (vals[x] == 0)
            continue;
        for (auto node : adj[x])
        {
            if (vals[node] < vals[x] + 1)
            {
                vals[node] = vals[x] + 1;
                parents[node] = x;
            }
        }
    }
    if (vals[n] > 0)
    {
        cout << vals[n] << endl;
        vector<int> ans;
        for (int k = n;; k = parents[k])
        {
            ans.push_back(k);
            if (k == 1)
                break;
        }
        reverse(ans.begin(), ans.end());
        for (auto x : ans)
            cout << x << ' ';
    }
    else
        cout << "IMPOSSIBLE";
}