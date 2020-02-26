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
int const MAXN = 21;
/*we can optimize dp to 1 dp [1 << MAXN]
  and use builtin__popcount to know the pos;
*/
LL dp[MAXN][1 << MAXN];
int n;
int a[MAXN][MAXN];
LL solve (int pos, int mask){
    if (pos == n) return 1;
    LL & ret = dp[pos][mask];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < n; i++){
        int bit = mask & (1 << i);
        if (a[pos][i] == 1 && !bit){
            ret += solve (pos + 1, mask | (1 << i));
        }
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < (1<<n); j++)
                dp[i][j] = -1;
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> a[i][j];
        cout << solve (0,0) << endl;
    }
}