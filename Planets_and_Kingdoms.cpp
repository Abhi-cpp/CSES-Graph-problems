#include <bits/stdc++.h>

using namespace std;
vector<int> adj[100009], radj[100009];
int ans[100009];
vector<int> st;
void dfs(int node, vector<int> &vis, int parents = 0)
{
    if (vis[node] != -1)
        return;
    vis[node] = 1;
    for (auto child : adj[node])
        dfs(child, vis, node);
    st.push_back(node);
}
void dfs1(int node, vector<int> &vis, int id, int parents = 0)
{
    if (vis[node] != -1)
        return;
    vis[node] = id;
    for (auto child : radj[node])
    {
        dfs1(child, vis, id, node);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        radj[b].push_back(a);
    }

    vector<int> vis(n + 1, -1), vis1(n + 1, -1);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == -1)
        {
            vis[0] = i;
            dfs(i, vis, 0);
        }
    }
    // for (auto x : st)
    //     cout << x << ' ';
    // cout << endl;
    int it = 1;
    while (!st.empty())
    {
        auto node = st.back();
        st.pop_back();
        if (vis1[node] == -1)
        {
            dfs1(node, vis1, it);
            ++it;
        }
        ans[node] = vis1[node];
    }
    cout << it-1 << endl;
    for (int i = 1; i <= n; i++)
        cout << ans[i] << " ";
}