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
int const MAXN = 2000 + 9;
int mod = 998244353;
LL add(LL a, LL b){
    return (a  + b) % mod;
}
LL sub(LL a, LL b){
    return ((a  - b) % mod + mod) % mod;
}
LL mul(LL a, LL b){
    a %= mod;
    return (a * b) % mod;
}
LL dp[MAXN][MAXN];
map<int,int> cnt;
vector<int> a;
LL solve(int i, int k){
    if(k == 0) return 1;
    if(i == sz(a)) return 0;
    LL & ret = dp[i][k];
    if(~ ret ) return ret;
    ret = 0;
    return ret = add(solve(i + 1, k), mul(a[i] , solve(i + 1, k - 1))); 
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n ; i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(auto x : cnt) a.pb(x.second);
    memset(dp, -1, sizeof dp);
    cout << solve(0,k);

}