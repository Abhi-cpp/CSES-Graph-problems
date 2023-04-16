#include <bits/stdc++.h>

using namespace std;
vector<int> adj[100002][2];
int n, m;
bool vis[100002];
void dfs(int node, int x)
{
    if (vis[node])
        return;
    vis[node] = true;
    for (auto child : adj[node][x])
        dfs(child, x);
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a][0].push_back(b);
        adj[b][1].push_back(a);
    }
    memset(vis, false, sizeof vis);
    dfs(1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            cout << "NO\n";
            cout << 1 << ' ' << i << endl;
            exit(0);
        }
    }
    memset(vis, false, sizeof vis);
    dfs(1, 1);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == false)
        {
            cout << "NO\n";
            cout << i << ' ' << 1 << endl;
            exit(0);
        }
    }
    cout << "YES";
}