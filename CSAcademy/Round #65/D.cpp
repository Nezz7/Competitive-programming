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
int const mod = 1e9 + 7;
int nxt[MAXN];
 struct BIT {
    vector<LL> bit;  // binary indexed tree
    LL n;
    BIT(LL n) {
        this->n = n;
        bit.assign(n, 0);
    }
    BIT(vector<LL> a) : BIT(a.size()) {
        for (size_t i = 0; i < a.size(); i++) add(i, a[i]);
    }
    LL sum(LL r) {
        LL ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1) ret += bit[r];
        return ret;
    }
    LL sum(LL l, LL r) {
        return sum(r) - sum(l - 1);
    }
    void add(int idx, LL delta) {
        for (; idx < n; idx = idx | (idx + 1)) bit[idx] += delta;
    }
};
LL add (LL a, LL b){
    return (a + b) % mod;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,q;
    cin >> n >> q;
    for(int i = 0; i <= n + 1; i++){
        nxt[i] = MAXN;
    }
    while(q--){
        int l,r;
        cin >> l >> r;
        nxt[l] = min(nxt[l],r);
    }
    for(int i = n; i >= 0 ; i--){
        nxt[i] = min(nxt[i + 1],nxt[i]);
    }
    BIT bit(MAXN);
    LL ans = 0;
    bit.add(n + 1,1);
    for(int i = n; i >= 0; i--){
        ans = bit.sum(i+1,nxt[i+1]);
        ans = add(ans,0);
        bit.add(i,ans);
    }
    cout << ans << endl;
}