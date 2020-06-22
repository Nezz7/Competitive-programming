#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 1e5 + 9;
LL dp[MAXN][1<<7];
int vis[MAXN][1<<7];
LL s[MAXN][10];
pair<LL,LL> a[MAXN];
int k,n,p;
set<int> st;
LL ans;
LL ans2;
LL solve (int i, int msk){
    if (i == n){
        if (__builtin_popcount(msk) == p) return 0;
        return -1e15;
    }
    LL & ret = dp[i][msk];
    if (vis[i][msk]) return ret;
    vis[i][msk] = true;
    ret = -1e15;
    int idx = a[i].second;
    for (int j = 0; j < p; j++){
        if ( (msk & (1 << j)) == 0){
            ret = max(ret,s[idx][j]+ solve (i+1,msk|(1<<j)));
        }
    }
    if (i - __builtin_popcount(msk) < k)
    ret = max(ret,a[i].first + solve(i+1,msk));
    else ret = max(ret,solve(i+1,msk));
    return ret;
}
 
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> p >> k;
    for (int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> s[i][j];
    sort(a,a+n);
    reverse(a,a+n);
    cout << solve(0,0);
}