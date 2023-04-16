#include <bits/stdc++.h>

using namespace std;
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

int main()
{
    int n, m;
    cin >> n >> m;
    dsu d;
    d.init(n);
    int com = n, siz = 1;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        if (d.find(a) != d.find(b))
        {
            d.join(a, b);
            --com;
            siz = max(d.sz(a), siz);
        }
        cout << com << ' ' << siz << endl;
    }
}