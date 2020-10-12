//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1917
#include <bits/stdc++.h>
#define _crt_secure_no_deprecate 
#define _crt_secure_no_warnings
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL)
#define ll long long
#define test int t; cin>>t; while(t--)
#define fo(i,initial,n) for(ll i=initial;i<=n;i++)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvi vector<vi>
#define sortarr(a, n) sort(a, a + n)
#define sortvec(a) sort(a.begin(), a.end())
#define endl "\n"
#define inp(a,n) fo(i,n)cin>>a[i]
#define printvec(a) fo(i,a.size())cout<<a[i]<<" "
#define FILL(arr,val) memset(arr,val,sizeof(arr)) 
#define INF 1000000000

using namespace std;


int main() {
    IOS;
    int k;
    vii ansList;
    while (cin>>k) {
        ansList.clear();
        fo(i, k+1, 2*k) {
            if ((k*i) % (i-k) == 0)
                ansList.push_back({ (k*i)/(i-k), i });
        }
        cout<<ansList.size()<<endl;
        fo(i, 0, ansList.size()-1) {
            cout << "1/"
                << k
                << " = 1/"
                << ansList[i].first
                << " + 1/"
                << ansList[i].second
                << endl;
        }
    }
    return 0;
}