//https://www.codechef.com/MAY20B/problems/TRPLSRT

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
#define foi(i, initial, n) for (lli i = initial; i <= n; i++)
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

struct op
{
    int i1 = -1;
    int i2 = -1;
    int i3 = -1;
    bool what = false;
};

op checkNext(vi a, vi b)
{
    op p;
    int n = a.size();

    fo(i,n)
        if(a[i]!=b[i]){
            p.i1 = i;break;}

    if(p.i1==-1)
        return p;

    foi(i,p.i1+1,n){
        if(a[i]!=b[i]){
            p.i2 = i;break;}
    }
    if(p.i2==-1){
        return p;
    }
    foi(i,p.i2+1,n){
        if(a[i]!=b[i])
            if(a[p.i1]> a[i] && a[p.i2] > a[i]){
                p.i3 = i;break;}
    } 
    if(p.i3 !=-1)
        p.what = true;      

    return p;
}
int main()
{
    IOS;

    test
    {
        vi a;
        int n, k;
        cin >> n >> k;
        int actualk = k;
        a.resize(n);
        inp(a, n);
        vector<op> operations;
        vi b = a;
        sort(b.begin(), b.end());
        bool possible = true;
        while (k && a != b)
        {

            op operation = checkNext(a, b);
            if (!operation.what)
            {
                possible = false;
                break;
            }
            operations.push_back(operation);
            int temp = a[operation.i1];
            a[operation.i1] = a[operation.i3];
            a[operation.i3] = a[operation.i2];
            a[operation.i2] = temp;
        }
        if (possible && a == b && operations.size() <= k)
        {
            cout << operations.size() << endl;
            fo(i, operations.size())
                    cout
                << operations[i].i1 + 1 << " " << operations[i].i2 + 1 << " " << operations[i].i3 + 1 << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }

    return 0;
}