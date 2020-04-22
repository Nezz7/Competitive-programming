#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    int a[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
    int ans = 0;
    for(int j = 0; j < m; j++){
        map<int,int> mp;
        for(int i = 0; i < n; i++){
            int x = (i) * m + (j + 1);
            if (!(j + 1 <= a[i][j] && a[i][j] <= (n-1) * m + (j+1))) continue;
            int d = x - a[i][j];
            if(d % m == 0){
                d = d/m;
                d += n;
                d %= n;
                mp[d]++;
            }
        }
        int mn = n;
        for(auto cur : mp){
            mn = min(cur.first + n - cur.second,mn);
        }
        ans += mn;
    }
    cout << ans << endl;
}