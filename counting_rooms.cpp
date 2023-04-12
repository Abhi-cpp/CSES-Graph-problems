#include <bits/stdc++.h>

using namespace std;

int X[] = {1, 0, -1, 0};
int Y[] = {0, -1, 0, 1};

void dfs(int i, int j, vector<string> &s, vector<vector<int>> &vis)
{
    if (i < 0 or j < 0 or i >= s.size() or j >= s[0].length() or vis[i][j] == 1 or s[i][j] == '#')
        return;
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int x = i + X[k];
        int y = j + Y[k];
        dfs(x, y, s, vis);
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &x : s)
        cin >> x;
    vector<vector<int>> vis(n, vector<int>(m, -1));
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == '.' and vis[i][j] == -1)
            {
                dfs(i, j, s, vis);
                ++cnt;
            }
        }
    }
    cout << cnt;
}