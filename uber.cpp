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
#define pb push_back
using namespace std;

const int ALPHABET_COUNT = 26;

struct trie{
	struct trie *children[ALPHABET_COUNT];
	bool endOfWord;
};

trie* createNode(){
	trie* newNode = (trie *)malloc(sizeof(trie));
	newNode->endOfWord = false;

	for(int i=0;i<ALPHABET_COUNT;i++) 
		newNode->children[i] = NULL;

	return newNode;
}

// void insertString(string str, struct trie* root){
// 	for(int i=0;i<str.length();i++){
// 		if(root->children[str[i] - 'a']==NULL){
// 			root->children[str[i]-'a'] = createNode();
// 			root = root->children[str[i]-'a'];
// 		} else {
// 			root = root->children[str[i]-'a'];
// 		}
// 	}
// }

int searchString(string str, struct trie* root){
	int ctr=0;
	struct trie* ptr = root;
	struct trie* inf = ptr;
	for(int i=0;i<str.length();i++){
		int index = (int)(str[i] - 'a');
		root = root->children[index];
		if(ptr->children[index] == NULL) return 1;	
		ptr = ptr->children[index];
		
		if(ptr->endOfWord){ 
			ctr++;		
			ptr = inf;
		}
	}

	return ctr;
}

int main(){
	IOS;

	int n; cin>>n;
	vector<string> vs(n); input(vs);
	sort(all(vs));

	struct trie* root = createNode();
	struct trie* ptr = root;

	for(int i=0;i<n;i++){
		root = ptr;
		// string str; cin>>str;
		string str = vs[i];
		for(int i=0;i<str.length();i++){
			char ch = str[i];
			if(root->children[ch-'a'] == NULL){
				root->children[ch-'a'] = createNode();
				root = root->children[ch-'a'];
			}
			else 
				root = root->children[ch-'a'];
		}
		root->endOfWord = true;
	}

	int ans=1;
	string res = vs[0];
	
	// cout<<searchString("kbcxyzpqabc", root);
	for(auto p: vs) cout<<p<<" ";
	cout<<endl;
	for(int i=0;i<n;i++){
		root = ptr;
		// ans = max(ans,searchString(vs[i],root));
		int len = searchString(vs[i],root);
		cout<<len<<endl;
		if(ans<len and len>=2){
			ans = len;
			res = vs[i];
		}
	}

	cout<<res<<endl;	
return 0;
}

/*
6
pq
abc
xyz
kbc
kbcxyzpq
abcxyzkbc
*/