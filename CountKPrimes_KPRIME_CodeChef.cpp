//https://www.codechef.com/LRNDSA05/problems/KPRIME
#include <bits/stdc++.h>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    cerr.tie(NULL);
#define lli long long
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define fo(i, n) for (lli i = 0; i < n; i++)
#define foi(i, initial, n) for (lli i = initial; i < n; i++)
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
#define MaxB 100001
using namespace std;

int nosP[MaxB];
void preproc()
{
    for (int i = 2; i <= MaxB; i++)
    {
        if (nosP[i] != 0)
            continue;
        else
        {
            nosP[i] = 1;
            for (int j = i + i; j <= MaxB; j += i)
            {
                nosP[j]++;
            }
        }
    }
}
int main()
{
    IOS;
    int a, b, ctr, k;
    preproc();
    fo(i, 20)
            cerr
        << i << " : " << nosP[i] << endl;
    test
    {
        ctr = 0;
        cin >> a >> b >> k;
        foi(i, a, b + 1)
        {
            if (nosP[i] == k)
                ctr++;
        }
        cout << ctr << endl;
    }
    return 0;
}