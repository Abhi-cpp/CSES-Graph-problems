#include <bits/stdc++.h>

using namespace std;
int vals[100009];
vector<int> adj[100009];
long long cnt = 0;
queue<int> q;
int vis[100009];
long long ans[100009];
bool iscycle = false;
void dfs(int node)
{
    q.push(node);
    if (vis[node] != -1)
    {
        cnt += ans[node];
        if (vis[node] == 2)
            iscycle = true;
        return;
    }
    vis[node] = 2;
    cnt += vals[node];
    for (auto child : adj[node])
    {
        dfs(child);
    }
    vis[node] = 1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> vals[i];
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
    }
    memset(vis, -1, sizeof vis);
    memset(ans, 0, sizeof ans);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == -1)
        {
            cnt = 0ll;
            iscycle = false;
            dfs(i);
            bool flag = true;
            cout << i << ' ' << cnt << endl;
            while (!q.empty())
            {
                cout << q.front() << ' ';
                ans[q.front()] = cnt;
                if (!iscycle)
                    cnt -= vals[q.front()];
                q.pop();
            }
            cout << endl;
        }
    }
    long long mx = 0;
    for (int i = 1; i <= n; i++)
    {
        // cout << i << ' ' << ans[i] << endl;
        mx = max(mx, ans[i]);
    }
    cout << mx;
}