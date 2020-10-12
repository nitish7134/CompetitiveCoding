    #include <bits/stdc++.h>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <utility>
    #define IOS                           \
        ios_base::sync_with_stdio(false); \
        cin.tie(NULL);                    \
        cout.tie(NULL);                   \
        cerr.tie(NULL)
    #define ll long long
    #define test  \
        int t;    \
        cin >> t; \
        while (t--)
    #define fo(i, n) for (ll i = 0; i < n; i++)
    #define foi(i, initial, n) for (ll i = initial; i < n; i++)
    #define fori(i, n) for (int i = 1; i <= n; i++)
    #define vi vector<int>
    #define ii pair<int, int>
    #define vii vector<ii>
    #define vvi vector<vi>
    #define int32 _int32
    #define sortarr(a, n) sort(a, a + n)
    #define sortvec(a) sort(a.begin(), a.end())
    #define endl "\n"
    #define inp(a, n) fo(i, n) cin >> a[i]
    #define printvec(a) fo(i, a.size()) cout << a[i] << " "

    using namespace std;

    const int N = 6;
    bool vis[N] = {false};
    float collTime[6][6];

    int sz = 0;
    struct Node
    {
        int pos;
        float time = FLT_MAX;
        vector<int> child;
        Node(int pos)
        {
            this->pos = pos;
        }
    };
    vector<Node> nodes;

    void dfs(Node u)
    {
        vis[u.pos] = true;
        for (int v : u.child)
        {
            if (!vis[nodes[v].pos] && u.time <= collTime[u.pos][v])
            {
                nodes[v].time = collTime[u.pos][v];
                dfs(nodes[v]);
            }
        }
        sz++;
    }

    void solve()
    {
        int n;
        cin >> n;
        vi a(n);
        inp(a, n);

        int worst = INT_MIN, best = INT_MAX;

        for (int i = 0; i < n; i++)
        {
            nodes.push_back(Node(i));
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (a[j] < a[i])
                {
                    collTime[i][j] = ((float)j - i) / (a[i] - a[j]);
                    collTime[j][i] = collTime[i][j];
                    nodes[i].child.push_back(j);
                    nodes[j].child.push_back(i);
                }
                else
                {
                    collTime[i][j] = -1;
                    collTime[j][i] = -1;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            memset(vis, false, sizeof vis);
            nodes[i].time = 0;
            dfs(nodes[i]);
            worst = max(worst, sz);
            best = min(best, sz);
            sz = 0;
            for (Node u : nodes)
            {
                u.time = FLT_MAX;
            }
        }

        cout << best << " " << worst << endl;
        nodes.clear();
    }

    int main()
    {
        IOS;
        test
        {
            solve();
        }
        return 0;
    }