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
int const MAXN = 2e6 + 9;
LL dp[70][2];
vector<int> r,l;
int n;
vector<int> get (LL x){
    vector<int> v;
    while (x > 0){
        v.push_back(x%2);
        x/=2;
    }
    return v;
}
LL solve (int pos, int cond){
    if (pos == r.size()) return 0;
    LL & ret = dp[pos][cond];
    if (ret != -1) return ret;
    int s = l[pos], e = r[pos];
    if (s < e) cond = true;
    ret = 0;
    if (e ^ s or cond)
    ret = max(ret,(1LL << (n - pos - 1)) + solve(pos +1, cond));
    ret = max(ret,solve(pos+1,cond));
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL a, b;
    cin >> a >> b;
    l = get(a);
    r = get(b);
    memset(dp,-1,sizeof dp);
    while (l.size() != r.size()) l.pb(0);
    reverse(all(l));
    reverse(all(r));
    n = sz(r);
    cout << solve(0,0);

}