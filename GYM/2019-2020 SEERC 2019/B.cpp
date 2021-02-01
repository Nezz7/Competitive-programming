#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define sz(x) (ll)(x).size()
const long double EPS = 1e-14;
const ll maxn = 1050;
const ll mod = 1e9 + 7;
ll p[maxn], x[maxn], y[maxn], r[maxn], t[maxn];
ll n, s1, s2;
ll dp[2][510][510];
 
bool cmp(ll i, ll j){
  return x[i] < x[j];
}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> s1 >> s2;
    for(ll i = 0 ; i < n ; ++i){
        p[i] = i;
        long long int xx, tt, yy, rr;
        cin >> xx >> tt >> yy >> rr;
        x[i] = xx, t[i] = tt, y[i] = yy, r[i] = rr;
    }
    sort(p, p + n, cmp);
    for(ll i = 0 ; i < 2 ; ++i)
        for(ll j = 0 ; j <= s1 ; ++j)
                for(ll k = 0 ; k <= s2; ++k)
                    dp[i][j][k] = 1e18;
    dp[0][0][0] = 0;
    for(ll i = 0 ; i < n ; ++i){
        ll idx = (i % 2);
        ll nxt = ((i + 1) % 2);
        for(ll j = 0 ; j <= s1 ; ++j)
            for(ll k = 0 ; k <= s2; ++k){
                if(dp[idx][j][k] == 1e18) continue;
                dp[nxt][j][k] = min(dp[nxt][j][k], dp[idx][j][k]);
                ll nx1 = j + x[p[i]];
                ll nx2 = k + y[p[i]];
                ll rem = max(0LL, nx1 - s1);
                if(j < s1)
                dp[nxt][min(nx1, s1)][min(s2, k + rem)] =
                 min(dp[nxt][min(nx1, s1)][min(s2, k + rem)], dp[idx][j][k] + t[p[i]]);
                dp[nxt][j][min(s2, nx2)] =
                 min(dp[nxt][j][min(s2, nx2)], dp[idx][j][k] + r[p[i]]);
            }
    }
    cout << (dp[n% 2][s1][s2] < 1e18 ? dp[n% 2][s1][s2]:-1) << '\n';
    return 0;
}