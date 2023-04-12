#include <bits/stdc++.h>
using namespace std;
int X[] = {1, 0, -1, 0};
int Y[] = {0, -1, 0, 1};
char Z[] = {'D', 'L', 'U', 'R'};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (auto &x : s)
        cin >> x;
    auto vis = s;
    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'A')
                start = {i, j};
            if (s[i][j] == 'B')
                end = {i, j};
            vis[i][j] = '.';
        }
    }

    queue<pair<int, int>> q;
    q.push(start);
    vis[start.first][start.second] = 'A';
    while (!q.empty())
    {
        auto cor = q.front();
        if (cor == end)
            break;
        q.pop();
        for (int k = 0; k < 4; k++)
        {
            int x = X[k] + cor.first;
            int y = Y[k] + cor.second;
            if (x < 0 or y < 0 or x >= n or y >= m or vis[x][y] != '.' or s[x][y] == '#')
                continue;
            vis[x][y] = Z[k];
            q.push({x, y});
        }
    }
    if (vis[end.first][end.second] == '.')
    {
        cout << "NO";
        exit(0);
    }
    cout << "YES\n";
    string ans = "";
    while (s[end.first][end.second] != 'A')
    {
        char c = vis[end.first][end.second];
        ans += c;
        if (c == 'U')
            ++end.first;
        else if (c == 'D')
            --end.first;
        else if (c == 'L')
            ++end.second;
        else
            --end.second;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    cout << ans << endl;
}