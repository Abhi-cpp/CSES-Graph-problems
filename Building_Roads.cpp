#include <bits/stdc++.h>
using namespace std;

class dsu
{
    vector<int> parents, s;

public:
    void init(int n)
    {
        parents.resize(n + 1);
        s.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parents[i] = i;
    }

    int find(int a)
    {
        if (a == parents[a])
            return a;
        return parents[a] = find(parents[a]);
    }

    void join(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        if (s[u] > s[v])
            swap(u, v);
        parents[u] = v;
        s[v] += s[u];
    }
};

int main()
{
    dsu d;
    int n, q;
    cin >> n >> q;
    d.init(n);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        d.join(a, b);
    }
    vector<pair<int, int>> ans;
    for (int i = 1; i < n; i++)
    {
        if (d.find(i) != d.find(i + 1))
        {
            d.join(i, i + 1);
            ans.push_back({i, i + 1});
        }
    }
    cout << ans.size() << endl;
    for (auto x : ans)
        cout << x.first << ' ' << x.second << endl;
}