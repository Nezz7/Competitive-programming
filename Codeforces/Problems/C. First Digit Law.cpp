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
int const MAXN = 1000 + 9;
LD dp[MAXN][MAXN];
LD p[MAXN];
LD get(LL x){
    LL cur = 2;
    LL ret = 0;
    while (true){
        if ( x / cur >= 1){
            ret += cur / 2;
        }else {
            cur /= 2;
            if ( x >= cur) ret+= x - cur + 1;
            break;
        }
        cur *=10;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,k;
    cin >> n;
    for (int i = 1; i <= n; i++){
        LL l,r;
        cin >> l >> r;
        p[i] = (get(r) - get(l - 1)) /(LD) (r - l + 1);
    }
    cin >> k;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            dp[i][j] = (1 - p[i]) * dp[i - 1][j] + dp[i - 1][max(j - 1,0)] * p[i];
        }
    }
    int x = (k * n + 99) /100;
    cout << setprecision(20);
    cout << dp[n][x];
}