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
int const MAXN = 100;
int p[MAXN];
LL dp [100][100][100];
int n,k;
LL solve (int pos, int mod, int c){
    if (pos == n){
        if (mod == 0 && 2*c == n) return 1;
        return 0;
    }
    LL & ret = dp[pos][mod][c];
    if (ret != -1) return ret;
    ret = 0;
    if (pos != n-1)
    ret += solve(pos+1,mod,c);
    ret += solve (pos+1,(mod + p[pos]) % k,c+1);
    return ret ;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int c = 0;
    while (T--){
        memset(dp, -1 ,sizeof dp);
        c++;
        cin >> n >> k;
        if (k == 0){
            cout  <<"Case "<< c << ": " << 0 << endl;
            continue;
        }
        p[0] = 1;
        for (int i = 1; i <= n; i++)
            p[i] = (2 * p[i-1]) % k;
        cout  <<"Case "<< c << ": " << solve (0,0,0) << endl;
    }
}