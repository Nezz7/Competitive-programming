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
int const MAXN = 2e5 + 9;
LL dp[MAXN][3];
LL a,b,n;
string s;
LL solve(int i, int p){
    if (i == n - 1) {
        if (p == 0) return a + 2 * b;
        return 2 * a + 3* b;
    }
    LL & ret = dp[i][p];
    if (ret != -1) return ret;
    ret  = 1e18;
    if(s[i] == p){
        ret = a + b * (s[i] + 1) + solve(i+1,p);
    }else {
        if(s[i] == 0) ret = min(a + b * 2 + solve(i + 1, 1),2 * a + 2*b + solve(i + 1, 0));
        else ret = 2 * a + 2 * b + solve(i + 1, 1);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        cin >> n >> a >> b;
        for (int i = 0; i <= n; i++){
            dp[i][0] = dp[i][1] = -1;
        }
        cin >> s;
        for(auto &c : s) c-='0';
        cout << solve(0,0)  << endl;
    }
}