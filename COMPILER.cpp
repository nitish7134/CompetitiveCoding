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
using namespace std;
int main()
{
    test
    {
        string s;
        cin >> s;
        int ctrl=0,ctrr=0,ans=0;
        for(int i=0; i< s.length();i++)
        {
			if(s[i]=='<')
				ctrl++;
			else
				ctrr++;
			if(ctrl==ctrr){
				ans = i+1;
			}
			else if(ctrr>ctrl)
				break;
		}
		cout<<ans<<endl;
    }
    return 0;
}