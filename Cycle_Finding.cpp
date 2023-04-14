#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edg;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edg.push_back({a, b, c});
    }
    vector<long long> dis(n + 1, 1e9);
    vector<int> parents(n + 1, -1);
    int isloop = -1;
    for (int i = 1; i <= n; i++)
    {
        isloop = -1;
        for (auto x : edg)
        {
            if (dis[x[1]] > dis[x[0]] + x[2])
            {
                dis[x[1]] = dis[x[0]] + x[2];
                parents[x[1]] = x[0];
                isloop = x[1];
            }
        }
    }
    if (isloop == -1)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES\n";
        int y = isloop;
        for (int i = 1; i <= n; i++)
        {
            y = parents[y];
        }
        vector<int> ans;
        for (int cur = y;; cur = parents[cur])
        {
            ans.push_back(cur);
            if (cur == y and ans.size() > 1)
                break;
        }
        reverse(ans.begin(), ans.end());
        for (auto x : ans)
            cout << x << ' ';
    }
}