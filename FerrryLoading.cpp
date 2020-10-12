//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=14&page=show_problem&problem=1202
#include <bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL)
#define ll long long
#define test int t; cin>>t; while(t--)
#define fo(i,n) for(ll i=0;i<n;i++)
#define foi(i,initial,n) for(ll i=initial;i<n;i++)
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

bool storedIn[205][10005];
bool dp[2][10005];

int main() {
    IOS;
    test{
        int L;
    cin>>L;
    vi cars;
    vi port, starport;
    int temp;
    while (true) {
        cin>>temp;
        if (temp!=0)
            cars.push_back(temp);
        else
            break;
    }
    int sum = 0;
    bool done = false;
    int finalL=0;
    int readTill = 0;
    int t=0, pt;
    fo(i, cars.size()) {
        sum += cars[i];
        done = true;
        pt = t; t ^= 1;
        fo(j, L+1) {

            if (!dp[pt][j])continue;
            if (j+cars[i] <= L && sum- (j+cars[i]) <=L) {
                dp[t][j+cars[i]] = true;
                done = false;
                finalL = j + cars[i];
                storedIn[t][finalL] = true;
                dp[t][finalL] = true;
            }
            if (sum-j < L) {
                dp[t][j] = true;
                done = false;
                finalL = j;
                storedIn[t][j] = false;
            }
        }
        if (done) {
            readTill = i; break;
        }
    }
    cout<<readTill<<endl;
    vector<string> answers(readTill);
    for (int i = readTill;i>=0;i++) {
        if (storedIn[i][finalL]) {
            answers[i] = "port";
            finalL -= cars[i];
        }
        else
        {
            answers[i] = "starboard";
        }

    }
    fo(i, readTill) {
        cout<<answers[i]<<endl;
    }

    }
    return 0;
}