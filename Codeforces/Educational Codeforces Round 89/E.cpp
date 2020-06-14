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
int a[MAXN], b[MAXN], mn[MAXN];
map<int,vector<int>> pos;
int const mod = 998244353;
LL mul(LL a, LL b){
    a %= mod;
    return (a * b) % mod;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        pos[x].pb(i);
        a[i] = x;
    }
    for(int i = 0; i < m; i++)
        cin >> b[i];
    mn[n] = 1e9;
    for(int i = n - 1; i >= 0; i--){
        mn[i] = min(a[i],mn[i + 1]);
    }
    if(mn[0] < b[0]){
        cout << 0;
        return 0;
    }
    for(int i = 0; i < m; i++){
        if(sz(pos[b[i]]) == 0){
            cout << 0;
            return 0;
        }
        int last = pos[b[i]].back();
        if(mn[last + 1] < b[i]){
            cout << 0;
            return 0;
        }
    }
    int ans = 1;
    int last = pos[b[0]].back();
    for(int i = 1; i < m; i++){
        int cur = pos[b[i]].back();
        for(int j = last; j < cur; j++){
            if(a[j] < b[i]) last = j;
        }
        ans = mul(ans,cur - last);
        last = cur;
    }
    cout << ans << endl;
}