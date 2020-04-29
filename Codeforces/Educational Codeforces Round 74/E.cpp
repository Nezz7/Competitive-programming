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
int const MAXN = 1<<21;
LL dp[MAXN];
int n,m;
int add[21],cnt[21][21],sum[21][MAXN];
LL solve(int msk){
    int i = __builtin_popcount(msk);
    if(i == m) return 0;
    LL & ret = dp[msk];
    if(~ret) return ret;
    ret = 1e18;
    for(int j = 0; j < m; j++){
        if(msk & (1 << j)) continue;
        int prev = sum[j][msk];
        int nxt = add[j] - prev;
        ret = min(ret,i * (prev - nxt) +  solve(msk ^ (1 << j)));
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    string s;
    cin >> s;
    for(int i = 1; i < n; i++){
        if(s[i] != s[i - 1]){
            int u = s[i] - 'a';
            int v = s[i - 1] - 'a';
            cnt[u][v]++;
            cnt[v][u]++;
            add[u]++;
            add[v]++;
        }
    }
    for(int i = 0; i < m; i++){
        for(int msk = 0; msk < (1 << m); msk++){
            if(msk & (1 << i)) continue;
            for(int j = 0; j < m; j++){
                if(msk & (1 << j)) sum[i][msk] += cnt[i][j];
            }
        }
    }
    memset(dp,-1,sizeof (dp));
    cout << solve(0);
}