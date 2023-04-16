#include <bits/stdc++.h>

using namespace std;

int edg[200009];
int vis[200009];
int dis[200009];
int val = 0;
queue<int> q;
void dfs(int node)
{
    q.push(node);
    if (vis[node] == 1)
    {
        val += dis[node];
        return;
    }
    vis[node] = 1;
    dfs(edg[node]);
    ++val;
}
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> edg[i];
    memset(vis, -1, sizeof vis);
    memset(dis, 0, sizeof dis);
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == -1)
        {
            val = 0;
            dfs(i);
            int rem = 1;
            while (!q.empty())
            {
                if (q.front() == q.back())
                    rem = 0;
                dis[q.front()] = val;
                val -= rem;
                q.pop();
            }
        }
    }
    for (int i = 1; i <= n; i++)
        cout << dis[i] << " ";
}