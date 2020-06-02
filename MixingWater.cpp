//https://codeforces.com/contest/1359/problem/C
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
        int h, c, t;
        cin >> h >> c >> t;
        
        
        float av = (float)h + c;
        av /= 2;
        float ans;
        if (av >= t)
            ans = 2;
        else
        {   
            float temp = h;
            ans = 1;
            float diff = abs(t - h);
            do{
            float delta = (c-h)/((4*ans*ans) -1);
            float temp1 = temp + delta;
            if(abs(temp1-t)>diff)
                break;
            ans+=2;
            diff = abs(temp1-t);
            temp = temp1;
            }while(true);
            if(abs(temp-t)>abs(av-t))
                ans = 2;
        }

        cout<<ans<<endl;
    }
    return 0;
}