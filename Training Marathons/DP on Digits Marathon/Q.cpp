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
int n;
int prime[90];
string a,b;
int dp[10][50][50][2][2];
int solve (int pos, int sum1, int sum2 ,int cond1, int cond2){
    if (pos == b.size()) return sum1 - sum2 > 0 && !prime[sum1 - sum2];
    int & ret = dp[pos][sum1][sum2][cond1][cond2];
    if (ret != -1) return ret;
    ret = 0;
    int l , r;
    if (cond1 && cond2) l = 0, r = 9;
    if (!cond1 && cond2) l = a[pos] - '0', r = 9;
    if (cond1 && !cond2) l = 0, r = b[pos] - '0';
    if (!cond1 && !cond2) l = a[pos]  - '0', r = b[pos]- '0';
    for (int i = l; i <= r; i++){
        int f1 = cond1 , f2 = cond2;
        int s1 = sum1, s2 = sum2;
        if (i > a[pos] - '0') f1 = 1;
        if (i < b[pos] - '0') f2 = 1;
        if ((n - pos) % 2 == 0 ) s1 += i;
        else s2 += i;
        ret += solve(pos + 1, s1, s2,f1,f2);
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
        n = b.size();
        while (sz(a) < sz(b)) a = '0' + a;
        cout << solve(0,0,0,0,0) << endl;
    }
}