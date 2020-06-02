#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#define ll long long
#define MAX 1000003
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

void solve()
{
	int n;
	cin >> n;
	int ans = 0;

	vector<ll> a(n);
	for (size_t i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] % 2)
			ans++;
	}
	map<int, int> mp, mp2;
	int ctr = 0, ctr1 = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] % 4 == 0)
			ctr++;
		else if (a[i] % 2 == 0)
		{
			ctr1++;
		}
		mp[i] = ctr;
		mp2[i] = ctr1;
	}
	ctr = 0;
	for (int i = 0; i < a.size() - 1; i++)
	{
		for (int j = i + 1; j < a.size(); j++)
		{
			if (i)
			{
				if ((!(mp[j] - mp[i - 1]) && !(mp2[j] - mp2[i - 1])) || ((mp[j] - mp[i - 1]) || mp2[j] - mp2[i - 1] > 1))
				{
					ans++;
				}
			}
			else
			{
				if ((!mp[j] && !mp2[j]) || mp[j] || mp2[j] > 1)
				{
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	IOS;
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}