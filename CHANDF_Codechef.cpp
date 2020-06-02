#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define ull unsigned long long
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
#define test  \
    int t;    \ 
    cin >> t; \
    while (t--)
#define vi vector<int>
#define vii vector<pair<int, int>>
#define ii pair<int, int>
#define ff first
#define ss second
using namespace std;


ull make1(ull z, int i)
{
    return (z | (1 << i));
}
ull makeZero(ull z, int i)
{
    return (z & ~(1 << i));
}

int findLastR(ull z, int r)
{
    z >>= (r + 1);
    ull t = (z & (-z));
    int res = log2(t) + 1 + r;
    return res;
}

ull recur(ull z,  int n, ull l, ull r, int lastChange)
{

    if (z >= l && z <= r)
        return z;

    if (z > r)
    {
        int k = findLastR(z, n);
        z = makeZero(z, k);
        z = make1(z,lastChange);
        return recur(z, k, l,r, k);
    }
  lastChange--;
  z = make1(z, lastChange);
  return recur(z,n,l,r,lastChange);
}

void solve()
{
    ull x, y, l, r;
    cin >> x >> y >> l >> r;
    if (x > y)
    {
        ull temp = x;
        x = y;
        y = temp;
    }
    // ull testL = l,testX = x, testY = y,testR = r;
    int ctrL = log2(l) + 1, ctrX = log2(x) + 1, ctrY = log2(y) + 1, ctrR = log2(r) + 1;
    ull z = x | y;
    z = recur(z, -1, l, r,-1);
    cout << z << endl;
}

int main()
{
    IOS;
    test
    {
        solve();
    }
    return 0;
}