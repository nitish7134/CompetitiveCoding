#include<bits/stdc++.h>
#include<iostream>
#include<string>
#include<vector>
#define ll long long
#define MOD 1000003
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define endl "\n"
#define all(a) (a).begin(),(a).end()
#define input(a) for(int i=0;i<n;i++) cin>>a[i];
using namespace std;

const int MAX = 1001; 
int ctr = 1;
int factor[MAX] = { 0 }; 
int factorof(int x){
    if(x<MAX)
        return factor[x];
    for(int i=2;i*i<x;i++){
		if(x%i==0) {
			return i;
		}
	}
	return x;
}
void generatePrimeFactors() 
{ 
    factor[1] = 1; 
  
    for (int i = 2; i < MAX; i++) 
        factor[i] = i; 
  
    for (int i = 4; i < MAX; i += 2) 
        factor[i] = 2; 
    for (int i = 3; i * i < MAX; i++) { 
        if (factor[i] == i) { 
            for (int j = i * i; j < MAX; j += i) { 
                if (factor[j] == j) 
                    factor[j] = i; 
            } 
        } 
    } 
}

int solve(int x,int k){
	//changes to be made
	if(x==1){
		return 0; 
	}

	int dup = factorof(x); 
	int j = x/factorof(x);
	int ctr=1;
	while(j!=1){
		if(factorof(j) == dup){
			ctr++;
		} else {
			dup = factorof(j);
			ctr++;
		}

		j = j/factorof(j);
	}

	if(ctr>=k)
		return 1;
	else return 0;
};

int main(){
	IOS;
	generatePrimeFactors();
	int t; cin>>t;
	while(t--){
		ll x,k; cin>>x>>k;
		cout<<solve(x,k)<<endl;
	}	
return 0;
}