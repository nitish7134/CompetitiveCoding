#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define MOD (int)(1e9 + 7)
#define IOS                           \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
#define endl "\n"
#define all(a) (a).begin(), (a).end()
#define input(a)                \
	for (int i = 0; i < n; i++) \
		cin >> a[i];
using namespace std;

const int N = 100010;
vector<int> adj[N], cost(N);
vector<int> st;
vector<bool> vis(N);

bool done = false;
const int MAX = 1001;

vector<int> factor(MAX);

int factorof(int x)
{
	if (x < MAX)
		return factor[x];
	for (int i = 2; i * i < x; i++)
	{
		if (x % i == 0)
		{
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
	for (int i = 3; i * i < MAX; i++)
	{
		if (factor[i] == i)
		{
			for (int j = i * i; j < MAX; j += i)
			{
				if (factor[j] == j)
					factor[j] = i;
			}
		}
	}
}
map<int, int> mp;
void calculateNoOFactors()
{
	int ans = 1;
	map<int, int>::iterator itr = mp.begin();
	while (itr != mp.end())
	{
		ans *= ((itr->second) % MOD);
		ans %= MOD;
		itr++;
	}
	cout << ans % MOD << endl;
}

void dfs(int node, int v)
{
	st.push_back(node);
	if (node == v)
	{
		return;
	}
	vis[node] = true;

	int flag = 0;
	for (int i = 0; i < adj[node].size(); i++)
	{
		int u = adj[node][i];
		if (!vis[u])
		{
			dfs(u, v);
			flag = 1;
		}
	}

	if (flag == 0)
	{
		st.pop_back();
	}
	return;
}

void workout(int x)
{
	while (x != 1)
	{
		if (mp[factorof(x)] < 1)
			mp[factorof(x)] = 1;
		mp[factorof(x)]++;
		x /= factorof(x);
	}
}
void solve()
{
	vis.clear();
	vis.resize(N);
	st.clear();
	int u, v;
	cin >> u >> v;
	mp.clear();
	dfs(u, v);

	for (int i = 0; i < (int)st.size(); i++)
	{
		workout(cost[st[i] - 1]);
	}

	calculateNoOFactors();
}

int main()
{
	IOS;
	int t;
	cin >> t;
	generatePrimeFactors();
	while (t--)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n - 1; i++)
		{
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		input(cost);
		int q;
		cin >> q;
		while (q--)
		{
			solve();
		}
	}
	cout << endl;

	return 0;
}