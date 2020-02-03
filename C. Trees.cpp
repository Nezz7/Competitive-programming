#include <bits/stdc++.h>
using namespace std;
int dp[MAXN][5];
int solve (int i,int last){
    if (i == (n+1)/2) return 0
    int & ret = dp[i][last];
    if (ret != -1) return ret;
    if (last == 0) x = min(a[i-1],a[n-1-i]);
    if (last == 0) x = max(a[i-1],a[n-1-i]);
    return
}
int main (){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

}
