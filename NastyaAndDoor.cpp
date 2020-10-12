//https://codeforces.com/contest/1341/problem/B
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
        int n, k;
        cin >> n >> k;
        int a[n];
        vector<bool> isPeak(n, false);
        fo(i, n)
                cin >>
            a[i];
        int prefix[n];
        prefix[0] = 0;
        fori(i, n - 2)
        {
            prefix[i] = prefix[i - 1];
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                isPeak[i] = true;
                prefix[i]++;
            }
        }
        prefix[n-1]=prefix[n-2];
        int ans = 0, l = 0;
        fo(i, n - k)
        {
            l = i;
            int temp = prefix[i + k - 1] - prefix[i];
            if (ans < temp)
            {
                l = i;
                ans = temp;
            }
        }
        cout<<ans<<" "<<l+1<<endl;
    }
    return 0;
}