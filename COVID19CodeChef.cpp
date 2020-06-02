//https://www.codechef.com/MAY20B/problems/COVID19
#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#define ll long long
#define MAX 1000003
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
	int n; cin>>n;
	vi a(n); input(a);

	int currMax=1;

	int globalMin=INT_MAX;
	int globalMax=1;
	for (int i = 0; i < n-1; ++i){
		if(a[i+1]-a[i]>2){
			globalMax = max(currMax,globalMax);
			globalMin = min(globalMin,currMax);
			currMax=1;
		} else if(a[i+1]-a[i]<=2){
			currMax++;
		}
	}
	globalMax = max(currMax,globalMax);
	globalMin = min(globalMin,currMax);
	cout<<globalMin<<" "<<globalMax<<endl;
}
return 0;
}