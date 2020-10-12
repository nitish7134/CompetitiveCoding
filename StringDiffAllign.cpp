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

int ED[101][101];

int main() {
    IOS;
    string a, b;
    getline(cin, a);
    getline(cin, b);
    int x, y;
    cin>>x>>y;
    int missmatchCtr=0;int delInsCtr=0;
    fo(i, a.length()+1)
        fo(j, b.length()+1)
        ED[i][j] = INT_MAX;
    fo(l, a.length()+1)
    {
        ED[l][0] = l;
    }
    fo(l, b.length()+1)
    {
        ED[0][l] = l;
    }
    fori(i, a.length())
    {
        fori(j, b.length())
        {
            vi temp(3);
            temp[0] = ED[i][j-1] +1;
            temp[1] = ED[i-1][j] +1;
            int mine;
            if (a[i] == b[j]) {
                temp[2] = ED[i-1][j-1];
                mine = min_element(temp.begin(), temp.end()) - temp.begin();
            }
            else {
                temp[2] = ED[i-1][j-1] +1;
                mine = min_element(temp.begin(), temp.end()) - temp.begin();

            }
            ED[i][j] = temp[mine];

        }
    }
    int i=a.length(), j=b.length();
    while (i!=0 || j!=0) {
        if (!(i==0 && j==0)) {
            if (ED[i][j] == ED[i-1][j]+1) {
                delInsCtr++;
                i--;
            }
            else if (ED[i][j] == ED[i][j-1]+1) {
                delInsCtr++;
                j--;
            }
            else {

                if (a[i]!=b[j])
                    missmatchCtr++;
                i--;j--;
            }
        }
    }
    cout<<delInsCtr<<endl;
    cout<<missmatchCtr<<endl;
    cout<<x*delInsCtr + y * missmatchCtr;
    return 0;
}