#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define MAX 1000003
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define input(a)                \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
using namespace std;

void solve()
{
    int a, b, c;
    cin >> a >> b >> c;
    int ctr = 0;

    for (int i = 1; i <= 7; i++)
    {
        if (((a - ((i & (1 << 2)) >> 2)) >= 0) and ((b - ((i & (1 << 1)) >> 1)) >= 0) and ((c - (i & 1)) >= 0))
        {
            a -= (((i & (1 << 2)) >> 2));
            b -= (((i & (1 << 1)) >> 1));
            c -= (i & (1));
            ctr++;
        }
    }

    cout << ctr << endl;
}

int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}