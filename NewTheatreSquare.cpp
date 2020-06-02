//http://codeforces.com/contest/1359/problem/B
#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    cerr.tie(NULL)
#define ll long long
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define foi(i, initial, n) for (ll i = initial; i < n; i++)
#define fori(i, n) for (int i = 1; i <= n; i++)
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vvi vector<vi>
#define int32 _int32
#define sortarr(a, n) sort(a, a + n)
#define sortvec(a) sort(a.begin(), a.end())
#define endl "\n"
#define inp(a, n) fo(i, n) cin >> a[i]
#define printvec(a) fo(i, a.size()) cout << a[i] << " "

using namespace std;
char Map[1000][1000];
int main()
{
    IOS;
    test
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        int whitectr = 0;
        fo(i, n)
        {
            fo(j, m)
            {
                cin >> Map[i][j];
                if (Map[i][j] == '.')
                    whitectr++;
            }
        }

        if (y >= 2 * x)
        {
            cout << whitectr * x << endl;
            continue;
        }
        ll cost = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (Map[i][j] == '.')
                {
                    int k = j;
                    int ctr = 0;
                    while (Map[i][k] == '.' and k <= m - 1)
                    {
                        k++;
                        ctr++;
                    }
                    j = k;

                    cost += (ctr / 2) * y;
                    cost += (ctr % 2) * x;
                }
            }
        }

        cout << cost << endl;
    }

    return 0;
}