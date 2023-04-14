#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> indegree(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        indegree[b]++;
    }
    queue<int> q;
    vector<int> ans;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    while (!q.empty())
    {
        auto node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto child : adj[node])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }
    if (ans.size() == n )
        for (auto x : ans)
            cout << x + 1 << ' ';
    else
        cout << "IMPOSSIBLE";
}