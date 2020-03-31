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
int const MAXN = 2e6;
int const MOD = 1e9 + 7;
vector<vector<int>> v;
LL fact[MAXN];
LL mul (LL a, LL b){
    return  ( a * b ) % MOD;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> n >> m;
    v.resize(m+1);
    for(int i = 0; i < n; i++){
        int k;
        cin >> k;
        for(int j = 0; j < k; j++){
            int x;
            cin >> x;
            v[x].pb(i);
        }
    }
    for(int i = 0; i <= m; i++) sort(all(v[i]));
    sort(all(v));
    LL ans = 1;
    int last = 1;
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fact[i] = mul(fact[i-1],i);
    for(int i = 2; i <= m; i++){
        if(v[i - 1]== v[i]) last++;
        else{
            ans = mul(ans,fact[last]);
            last = 1;
        }
    }
    ans = mul(ans,fact[last]);
    cout << ans << endl;
}