#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> vm, va;
vector<vector<char>> pa;
vector<string> state;
int X[] = {1, 0, -1, 0};
int Y[] = {0, -1, 0, 1};
char Z[] = {'D', 'L', 'U', 'R'};
int n, m;
pair<int, int> ansc = {-1, -1};
void bfs(queue<pair<int, int>> q)
{
    while (!q.empty())
    {
        auto cor = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = cor.first + X[i];
            int y = cor.second + Y[i];
            if (x < 0 or y < 0 or x >= n or y >= m or state[x][y] == '#' or vm[x][y] != -1)
                continue;
            vm[x][y] = vm[cor.first][cor.second] + 1;
            q.push({x, y});
        }
    }
}
void bfs1(queue<pair<int, int>> q)
{
    while (!q.empty())
    {
        auto cor = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = cor.first + X[i];
            int y = cor.second + Y[i];
            if (x < 0 or y < 0 or x >= n or y >= m or state[x][y] == '#' or va[x][y] != -1)
                continue;
            // checking for monsters
            if (vm[x][y] != -1 and vm[x][y] <= va[cor.first][cor.second] + 1)
                continue;
            va[x][y] = va[cor.first][cor.second] + 1;
            pa[x][y] = Z[i];
            q.push({x, y});
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if ((i == 0 or j == 0 or i == n - 1 or j == m - 1) and (va[i][j] != -1))
                ansc = {i, j};
        }
    }
}
int main()
{
    cin >> n >> m;
    vm.resize(n, vector<int>(m, -1));
    va.resize(n, vector<int>(m, -1));
    pa.resize(n, vector<char>(m, '.'));
    state.resize(n);
    for (auto &x : state)
        cin >> x;
    queue<pair<int, int>> mq, aq;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (state[i][j] == 'A')
            {
                pa[i][j] = '$';
                aq.push({i, j});
                va[i][j] = 0;
            }
            else if (state[i][j] == 'M')
            {
                mq.push({i, j});
                vm[i][j] = 0;
            }
        }
    }
    bfs(mq);
    bfs1(aq);
    if (ansc == make_pair(-1, -1))
    {
        cout << "NO\n";
        exit(0);
    }
    string ans;
    while (pa[ansc.first][ansc.second] != '$')
    {
        char c = pa[ansc.first][ansc.second];
        ans += c;
        if (c == 'U')
            ++ansc.first;
        else if (c == 'D')
            --ansc.first;
        else if (c == 'L')
            ++ansc.second;
        else
            --ansc.second;
    }
    reverse(ans.begin(), ans.end());
    cout << "YES\n"
         << ans.length() << endl
         << ans << endl;
}