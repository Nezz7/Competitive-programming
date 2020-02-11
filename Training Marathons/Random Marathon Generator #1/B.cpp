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
string s;
LL dp [20][2];
int x;
LL get (LL x){
    LL ret = 5;
    int i = 0;
    while (ret <= x){
        i++;
        ret *=10;
    }
    return i;
}
LL solve (int pos, int cond){
    if (pos == sz(s)) return 1;
    LL & ret = dp[pos][cond];
    if (ret != -1) return ret;
    ret = 0;
    int lm = 9;
    if (!cond) lm = s[pos] - '0';
    int c =  s[pos] - '0';
    for (int i = 0; i <= lm; i++){
        int f = cond;
        if (i < s[pos] - '0') f  = 1;
        if (sz(s) - pos  > x ) ret += c * solve(pos + 1, f);
        else {
            if (f == 0){
            if (9 - i  > c ) continue;
            }
            cout << "i :" << 9  - i << endl;
            ret += solve (pos + 1, f);
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n;
    cin >> n;
    memset(dp,-1,sizeof dp);
    x = get (n);
    debug(x)
    s = to_string(n);
    cout << s << endl;
    cout << solve (0,0) / 2;
}