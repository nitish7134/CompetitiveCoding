    #include <bits/stdc++.h>
    #define _crt_secure_no_deprecate
    #define _crt_secure_no_warnings
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
    #define fo(i, initial, n) for (ll i = initial; i <= n; i++)
    #define vi vector<int>
    #define ii pair<int, int>
    #define vii vector<ii>
    #define vvi vector<vi>
    #define sortarr(a, n) sort(a, a + n)
    #define sortvec(a) sort(a.begin(), a.end())
    #define endl "\n"
    #define inp(a, n) fo(i, n) cin >> a[i]
    #define printvec(a) fo(i, a.size()) cout << a[i] << " "
    #define FILL(arr, val) memset(arr, val, sizeof(arr))
    #define INF 1000000000
    using namespace std;

    int main()
    {
        IOS;
        test
        {
            int n;
            cin >> n;
            int mat[n][n];
            fo(i, 0, n-1)
            {
                fo(j, 0, n -1)
                        cin >>
                    mat[i][j];
            }
            int ctr = 0;
            bool state= false;
            for (int i = n - 1; i > 0; i--)
            {
                if ((mat[0][i] == i + 1) == state)
                {
                    ctr++;
                    state= !state;
                }
            }
            cout << ctr << endl;
        }

        return 0;
    }