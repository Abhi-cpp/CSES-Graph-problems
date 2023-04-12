#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> arr(n + 1, (vector<long long>(n + 1, 1e17)));
    while (m--)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
        arr[b][a] = min(arr[b][a], c);
    }
    for (int i = 0; i <= n; i++)
        arr[i][i] = 0;
    for (int k = 1; k <= n; ++k)
    {
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                arr[i][j] = min(arr[i][j], arr[i][k] + arr[k][j]);
            }
        }
    }
    for (auto &x : arr)
    {
        for (auto &y : x)
            if (y >= 1e17)
                y = -1;
    }
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << arr[a][b] << endl;
    }
}