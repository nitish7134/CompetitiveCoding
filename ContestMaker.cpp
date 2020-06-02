#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 998244353
#define test  \
    int t;    \
    cin >> t; \
    while (t--)
#define init(arr, val) memset(arr, val, sizeof(arr))
#define loop(i, a, b) for (int i = a; i < b; i++)
#define loopr(i, a, b) for (int i = a; i >= b; i--)
#define loops(i, a, b, step) for (int i = a; i < b; i += step)
#define looprs(i, a, b, step) for (int i = a; i >= b; i -= step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST                          \
    ios_base::sync_with_stdio(false); \
    cin.tie();                        \
    cout.tie();
#define FILE_READ_IN freopen("input.txt", "r", stdin);
#define FILE_READ_OUT freopen("output.txt", "w", stdout);
#define all(a) a.begin(), a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const ll maxn = 1e5;
const ll inf = 1e9;
const double pi = acos(-1);
int n, k;
int maxSame = 1;
map<int, int> nos, freq;
int factorial[1001];
int fact(int n)
{
    if (factorial[n] != 0 or !n)
        return factorial[n];
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    factorial[n] = res;
    return res;
}
int nCr(int n, int r)
{
    if (r > n)
        return 0;
    if(r==0)
        return 1;
    return fact(n) / (fact(r) * fact(n - r));
}

int solve(int m, int i)
{
    if(i>maxSame)
        return 0;
    if (m == 0)
        return 1;
    i++;
    int ans = 0;
    for (int j = m; j >= 0; j--)
    {
        if (freq.find(i) != freq.end())
            ans += (pow(i, j) * nCr(freq[i], j) * solve(m - j, i));
        else
        {
           continue;// ans += solve(m, i);
        }
        ans %= MOD;
    }
    return (ans % MOD);
}
int main()
{
    cin >> n >> k;
    int ans = 0;
    V<int> dif(n);
    loop(i, 0, n)
    {
        cin >> dif[i];
        if (nos.find(dif[i]) != nos.end())
            nos[dif[i]]++;
        else
            nos.insert({dif[i], 1});
    }

    auto i = nos.begin();
    for (; i != nos.end(); i++)
    {
        if (i->second > maxSame)
            maxSame = i->second;
    }

    i = nos.begin();
    for (; i != nos.end(); i++)
    {
        if (freq.find(i->second) != freq.end())
            freq[i->second]++;
        else
        {
            freq.insert({i->second, 1});
        }
    }

    cout << solve(k, 0) << endl;

    return 0;
}