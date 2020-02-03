#include <bits/stdc++.h>
#define LL long long int
using namespace std;
LL dp[(1<<19)][19];
LL c[19][19],a[19];
int n,m,k;
LL solve (bitset<18> mask, int last){
    if (mask.count() == m) return 0;
    int id = mask.to_ulong();
    LL  & ret = dp[id][last];
    if (ret != -1) return ret;
    for (int i = 0; i < n; i++){
        bitset<18> cur = mask;
        if (cur[i] == 0){
            cur[i] = 1;
            ret = max(ret,a[i] + c[last][i] + solve(cur,i));
        }
    }
    return ret;
}
int main(){
    memset(dp,-1,sizeof dp);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < k; i++){
        int x,y,b;
        cin >> x >> y >> b;
        x--,y--;
        c[x][y] = b;
    }
    bitset<18> msk;
    cout << solve(msk,18);
}
