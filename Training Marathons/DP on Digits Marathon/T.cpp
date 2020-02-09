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
int prime[90];
string a,b;
LL dp[20][20][2][2][2];
LL solve (int pos, int last, int cond1, int cond2,int sum){
    if (pos == b.size()) return sum;
    LL & ret = dp[pos][last][cond1][cond2][sum];
    if (ret != -1) return ret;
    ret = 0;
    int l , r;
    if (cond1 && cond2) l = 0, r = 9;
    if (!cond1 && cond2) l = a[pos] - '0', r = 9;
    if (cond1 && !cond2) l = 0, r = b[pos] - '0';
    if (!cond1 && !cond2) l = a[pos]  - '0', r = b[pos]- '0';
    for (int i = l; i <= r; i++){
        int f1 = cond1 , f2 = cond2;
        int s = sum;
        if (i > a[pos] - '0') f1 = 1;
        if (i < b[pos] - '0') f2 = 1;
        if (last == 4 && i == 9) s = 1;
        ret += solve(pos + 1, i,f1,f2,s);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        memset(dp,-1,sizeof dp);
        cin >> b;
        a = "1";
        while (sz(a) < sz(b)) a = '0' + a;
        cout << solve(0,0,0,0,0) << endl;
    }
}