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
int const MAXN = 2000;
int const MOD = 1e9 + 7;
LL p [MAXN], dp[MAXN][MAXN][2][2];
int m, d;
string a,b;
LL solve (int pos, int res, int cond1, int cond2){
    if (pos == sz(a)) return (res == 0);
    LL & ret = dp[pos][res][cond1][cond2];
    if (ret != -1) return ret;
    ret = 0;
    int l,r;
    if (cond1 && cond2) l = 0, r = 9;
    if (cond1 && !cond2) l = 0, r = b[pos] - '0';
    if (!cond1 && cond2)  l = a[pos] - '0', r = 9;
    if (!cond1 && !cond2) l = a[pos] - '0', r = b[pos] - '0';

    for (int i = l; i <= r; i++){
        int f1 = cond1;
        int f2 = cond2;
        if (i > a[pos] - '0') f1 = 1;
        if (i < b[pos] - '0') f2 = 1;
        if (pos % 2 == 1 && i != d) continue;
        if (pos % 2 == 0 && i == d) continue;
        ret = (ret + solve(pos + 1, (p[(sz(a) - 1 - pos)] * i + res) % m, f1,f2))%MOD;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    p[0] = 1;
    cin >> m >> d;
    cin >> a >> b;
    memset(dp,-1,sizeof dp);
    for (int i = 1; i < MAXN; i++){
        p [i] = (p[i - 1] * 10LL) % m ;
    }
    cout << solve(0,0,0,0);
    
}