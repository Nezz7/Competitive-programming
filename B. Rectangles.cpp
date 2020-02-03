#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int n, m;
LL dp[55][55],a[55][55];
LL C (int n, int k){
    if (k == 0 or k == n) return 1;
    LL & ret = dp[n][k];
    if (ret != -1) return ret;
    return ret =  C(n-1,k-1)+ C(n-1,k);
}
LL get (int n ){
    LL ret =0;
    for (int i = 2; i<= n;i++)
        ret+=C(n,i);
    return ret;
}
int main (){
    memset(dp,-1,sizeof dp);
    cin >> n >> m ;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    LL ans = 0;
    for (int i = 0 ; i < n ;i++){
        LL cur = 0;
        for (int j = 0 ; j < m ;j++)
            cur += a[i][j];
        ans += get(cur) + get(m-cur);
    }
    for (int j = 0 ; j < m ;j++){
      LL cur = 0;
      for (int i = 0 ; i < n ;i++)
            cur += a[i][j];
        ans += get(cur) + get(n-cur);
    }
    cout << ans + n*m<< endl;
}
