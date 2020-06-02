//https://codeforces.com/contest/1359/problem/D
#include<bits/stdc++.h>
#define ll long long
#define MAX 1000003
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define all(a) (a).begin(),(a).end()
#define input(a) for(int i=0;i<a.size();i++) cin>>a[i];
#define test int t; cin>>t; while(t--)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define ff first
#define ss second
using namespace std;

void solve(){
	float h,c,final; cin>>h>>c>>final;
	float last = h;
	float i=0;
	float max =0;
	

	for(i=1; ; i++){
		float next;
		if((int)i%2==0){
			next = last*(i)/(i+1) + h/(i+1);
		} else {
			next = (last*i-1)/(i+1) + c/(i+1);
		}	

		if(last-next>0){
			max = last;
			break;
		} else {
			
			if((final-next)*(final-last)<=0){
				int ans=0;
				(final-next) < (final-last) ? ans=i : ans=i-1;
				cout<<"asd"<<ans<<endl;
				return;
			}

			last = next;

		}
	}

	if(max<=final){
		cout<<i<<endl;
		return;
	}
}

int main(){
	IOS;
	test{
		solve();
	}
return 0;
}

/*
3
30 10 20
41 15 30
18 13 18
*/