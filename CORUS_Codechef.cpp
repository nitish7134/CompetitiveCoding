//https://www.codechef.com/MAY20B/problems/CORUS
#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#define ll long long
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define all(a) (a).begin(),(a).end()
#define input(a) for(int i=0;i<n;i++) cin>>a[i];
#define test int t; cin>>t; while(t--)
#define vi vector<int>
#define vii vector<pair<int,int>>
#define ii pair<int,int>
#define ff first
#define ss second
using namespace std;

int main(){
	IOS;
	test{
	int arr[26]={0};
	int n,q; cin>>n>>q;
	string str; cin>>str;
	for(int i=0;i<n;i++){
		arr[str[i]-'a']++;
	}
	while(q--){
		int c; cin>>c;
		int ans=0;
		for(int i=0;i<26;i++){
			if(arr[i]>c) ans+=(arr[i]-c); 
		}
		cout<<ans<<endl;
	}
}
return 0;
}