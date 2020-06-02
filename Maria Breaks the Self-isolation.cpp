//http://codeforces.com/contest/1358/problem/B
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL)
#define lli long long
#define test int t; cin>>t; while(t--)
#define fo(i,n) for(lli i=0;i<n;i++)
#define foi(i,initial,n) for(lli i=initial;i<n;i++)
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
#define printvec(a) fo(i,a.size())cout<<a[i]<<" "

using namespace std;


int main(){
    IOS;
    test{
    int n; 
    cin>>n; 
	vi a(n+1); //input(a);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a.begin(),a.end());
	int i;
	int no=0,yes=0;
	int ans=0;
	for(i=1;i<=n;i++){
		if(a[i]>i) no++;
		else{
			yes++;
			ans = yes+no;
		} 
	}
	cout<<ans+1<<endl;
    }
    return 0;
}