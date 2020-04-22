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
int const MAXN = 2e3 + 9;
LL dp[MAXN][MAXN];
inline LL add(LL x, LL y){
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
inline LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    string s;
    string t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    for (INT )
    for (int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(s[i] == t[j])
        }
    }
}