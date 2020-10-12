//https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3399
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
    int A, B, C, X, Y;
    while (scanf("%d %d %d %d %d", &A, &B, &C, &X, &Y) == 5) {
        if (A == 0)  break;

        int used[60] ={};
        used[A] = used[B] = used[C] = used[X] = used[Y] = 1;
        bool done = 0;
        int i, j;
        for (i = 1; i <= 52; i++) {
            if (used[i])    continue;
            int arr[3] ={ X, Y, i }, w = 0;
            if (arr[0] > A)  w++;
            if (arr[1] > B)  w++;
            if (arr[2] > C)  w++;
            if (w < 2) continue;
            w = 0;
            if (arr[0] > A)  w++;
            if (arr[2] > B)  w++;
            if (arr[1] > C)  w++;
            if (w < 2) continue;
            w = 0;
            if (arr[1] > A)  w++;
            if (arr[0] > B)  w++;
            if (arr[2] > C)  w++;
            if (w < 2) continue;
            w = 0;
            if (arr[1] > A)  w++;
            if (arr[2] > B)  w++;
            if (arr[0] > C)  w++;
            if (w < 2) continue;
            w = 0;
            if (arr[2] > A)  w++;
            if (arr[0] > B)  w++;
            if (arr[1] > C)  w++;
            if (w < 2) continue;
            w = 0;
            if (arr[2] > A)  w++;
            if (arr[1] > B)  w++;
            if (arr[0] > C)  w++;
            if (w < 2) continue;
            done = 1;
            cout<<i;
            break;
        }
        if (!done) cout<<-1;
        cout<<endl;
    }
    return 0;
}
