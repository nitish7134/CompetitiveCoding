//http://codeforces.com/contest/1358/problem/D
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

void fillPrefixSum(vi arr, int n, int prefixSum[]) 
{ 
    prefixSum[0] = arr[0]; 
    for (int i = 1; i < n; i++) 
        prefixSum[i] = prefixSum[i-1] + arr[i]; 
} 




int main()
{
    IOS;
    int n;
    int x;
    cin >> n >> x;
    vi d;
    int temp;
    fo(i, n)
    {
        cin >> temp;
        fori(j, temp)
            d.push_back(j);
    }
    d.insert(d.end(),d.begin(),d.begin()+x);
    int prefixSum[n]; 
    int maxElementIndex = max_element(d.begin(),d.end()) - d.begin();
    fillPrefixSum(d, d.size(), prefixSum); 



    return 0;
}