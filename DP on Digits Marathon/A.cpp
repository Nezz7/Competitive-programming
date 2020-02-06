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
int const MAXN = 1e4 + 9;
int dp[12][100][100][3];
vector<int> a;
int k;
int cnt (int pos, int res1, int res2, int cond){
    if (pos == a.size()){
        if (res1 == 0 && res2 == 0) return 1;
        return 0;
    }
    int& ret = dp[pos][res1][res2][cond];
    if (ret != -1) return ret;
    ret = 0;
    int LMT;
    if (cond){
        LMT = 9;
    }else LMT = a[pos];
    LL p = 1;
    for (int i = 0; i < sz(a) - pos - 1; i++){
        p*= 10;
    }
    p %= k;
    for (int i = 0; i <= LMT; i++){
        int f = cond;
        if (i < LMT) f = 1;
        ret += cnt (pos + 1, ((LL) i*p + res1) % k, ((LL) i + res2) % k,f);
    }
    return ret;
}
int solve (int x){
    a.clear();
    memset(dp,-1,sizeof dp);
    while (x > 0){
        a . push_back(x % 10);
        x/=10;
    }
    reverse (all(a));
    return cnt(0,0,0,0);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int c = 0;
    while (T--){
        c++;
        int a, b;
        cin >> a >> b >> k;
        if(k >= 100){
            cout << "Case " << c << ": " << 0 << endl;
            continue;
        }
        cout << "Case " << c << ": " << solve(b) - solve(a - 1) << endl;
    }
}