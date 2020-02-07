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
int dp[10][90][2][2];
int solve (int pos, int sum, int cond1, int cond2){
    if (pos == b.size()) return !prime[sum];
    int & ret = dp[pos][sum][cond1][cond2];
    if (ret != -1) return ret;
    ret = 0;
    int l , r;
    if (cond1 && cond2) l = 0, r = 9;
    if (!cond1 && cond2) l = a[pos] - '0', r = 9;
    if (cond1 && !cond2) l = 0, r = b[pos] - '0';
    if (!cond1 && !cond2) l = a[pos]  - '0', r = b[pos]- '0';
    for (int i = l; i <= r; i++){
        int f1 = cond1 , f2 = cond2;
        if (i > a[pos] - '0') f1 = 1;
        if (i < b[pos] - '0') f2 = 1;
        ret += solve(pos + 1, sum + i,f1,f2);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    prime[0] = prime[1] = 1;
    for (int i = 2; i < 90; i++)
        if (prime[i] == 0){
            for (int j = 2 * i; j < 90; j+= i)
                prime[j] = i;
        }
    int T;
    cin >> T;
    while (T--){
        memset(dp,-1,sizeof dp);
        cin >> a >> b;
        while (sz(a) < sz(b)) a = '0' + a;
        cout << solve(0,0,0,0) << endl;
    }
}