//http://codeforces.com/problemset/problem/1332/A
#include <iostream>
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);                   \
    cerr.tie(NULL);
#define lli long long
#define fo(i, n) for (lli i = 0; i < n; i++)
#define foi(i, initial, n) for (lli i = initial; i < n; i++)
#define fori(i, n) for (int i = 1; i <= n; i++)
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define vvi vector<vi>
#define int32 _int32
#define endl "\n"
#define printvec(a) fo(i, a.size()) cout << a[i] << " : "
#define ASCII_SIZE 256
using namespace std;

int main()
{
    IOS;
    int T;
    cin >> T;
    int a, b, c, d;
    int x[3], y[3];
    while (T--)
    {
        cin >> a >> b >> c >> d;
        for (size_t i = 0; i < 3; i++)
        {
            cin >> x[i] >> y[i];
        }
        if ((a + b > 0 && x[1] == x[2]) || (c + d > 0 && y[1] == y[2]))
        {
            cout << "No" << endl;
            continue;
        }
        if (x[0] - a + b >= x[1] && x[0] - a + b <= x[2])
            if (y[0] - c + d >= y[1] && y[0] - c + d <= y[2])
            {
                cout << "Yes" << endl;
                continue;
            }
        cout << "No" << endl;
    }

    return 0;
}