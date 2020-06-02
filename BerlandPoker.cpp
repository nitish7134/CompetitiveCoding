//http://codeforces.com/contest/1359/problem/0
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

int main()
{
    IOS;
    test
    {
        int n, m, k;
        cin >> n >> m >> k;
        int t = (n / k);
        if (t > m)
        {
            cout << m << endl;
            continue;
        }
        else
        {
            m -= t;
            int eachp = m % (k - 1) == 0 ? m / (k - 1) : m / (k - 1) + 1;
            cout << t - eachp << endl;
            continue;
        }
    }

    return 0;
}