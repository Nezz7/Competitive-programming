#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 22;
int dp[(1<<MAXN)];
int a[MAXN];
bool balance (int bit){
    int ret = 0;
    for (int i = 0; i < MAXN; i++){
        if(bit & (1<<i)) ret += a[i];
    }
    return ret == 0;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int u , v, p;
        cin >> u >> v >> p;
        a[u] -= p;
        a[v] += p;
    }
    dp[0] = 0;
    for (int bit = 1; bit < (1<<n); bit++){
        for (int i = 0; i < n; i++)
            if(bit & (1 << i)){
                dp[bit] = max(dp[bit],dp[bit & (~ (1<<i))]);
            }
        dp[bit] += balance(bit);       
    }
    cout << n - dp[(1 << n) - 1];
}