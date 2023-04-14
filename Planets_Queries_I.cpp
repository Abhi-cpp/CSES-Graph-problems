#include <bits/stdc++.h>

using namespace std;
#define fast                 \
    ios::sync_with_stdio(0); \
    cin.tie(0);              \
    cout.tie(0);
int parents[200001][30];
int main()
{
    fast;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> parents[i][0];
    for (int i = 1; i < 30; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            parents[j][i] = parents[parents[j][i - 1]][i - 1];
        }
    }
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        for (int i = 0; i < 30; i++)
        {
            if (b & (1 << i))
            {
                a = parents[a][i];
            }
        }
        cout << a << '\n';
    }
}