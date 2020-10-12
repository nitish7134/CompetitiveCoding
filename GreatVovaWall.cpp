//https://codeforces.com/contest/1092/problem/D1
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL)
#define ll long long
#define test int t; cin>>t; while(t--)
#define fo(i,n) for(ll i=0;i<n;i++)
#define foi(i,initial,n) for(ll i=initial;i<n;i++)
#define fori(i,n) for(int i=1;i<=n;i++)
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvi vector<vi>
#define int32 _int32
#define sortarr(a, n) sort(a, a + n)
#define sortvec(a) sort(a.begin(), a.end())
#define endl "\n"
#define inp(a,n) fo(i,n)cin>>a[i]
#define printvec(a) fo(i,a.size())cout<<a[i]<<" "; cout<<endl

using namespace std;
vi a;
void func(int l, int r, int maxL){

    if(l==r){

    }
    if(l==r+1){

    }
    int i = max_element(a.begin(),a.end()) - a.begin();
    func(0,i,a[i]);
    fill(0,i,a[i]);
    func(i+1,r,a[i]);
    fill(i+1,r,a[i]);
}
void fill(int l,int r,int maxL){

}
int main(){
    IOS;
    int n;
    cin>>n;
    
    a.resize(n);
    inp(a,n);
    int i = max_element(a.begin(),a.end()) - a.begin();
    func(0,i,a[i]);
    fill(0,i,a[i]);
    func(i+1,n,a[i]);
    fill(i+1,n,a[i]);
    
    fo(j,n){
        if(a[j]!=a[i]){
            cout<<"NO";return 0;
        }
    }
    cout<<"YES";
    return 0;
}