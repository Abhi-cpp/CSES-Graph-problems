#include <bits/stdc++.h>

using namespace std;

struct node
{
    int a, b;
    long long weight;
};

class dsu
{
    vector<int> parents, siz;

public:
    void init(int n)
    {
        siz.resize(n + 1, 1);
        parents.resize(n + 1);
        iota(parents.begin(), parents.end(), 0);
    }

    int find(int a)
    {
        if (parents[a] == a)
            return a;
        return parents[a] = find(parents[a]);
    }

    void join(int a, int b)
    {
        a = find(parents[a]);
        b = find(parents[b]);
        if (a == b)
            return;
        if (siz[a] > siz[b])
            swap(a, b);
        parents[a] = b;
        siz[b] += siz[a];
    }

    int sz(int a)
    {
        return siz[find(a)];
    }
};

bool cmp(node &a, node &b)
{
    return a.weight < b.weight;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<node> edg(m);
    for (auto &x : edg)
        cin >> x.a >> x.b >> x.weight;
    sort(edg.begin(), edg.end(), cmp);
    dsu d;
    d.init(n);
    long long sum = 0;
    for (auto x : edg)
    {
        if (d.find(x.a) != d.find(x.b))
        {
            sum += x.weight;
            d.join(x.a, x.b);
        }
    }
    if (d.sz(1) == n)
        cout << sum;
    else
        cout << "IMPOSSIBLE";
}