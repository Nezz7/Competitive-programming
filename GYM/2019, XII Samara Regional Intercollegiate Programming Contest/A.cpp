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
int occ[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    int a[n];
    int dp[n];
    for (int i = 0; i < n; i++){
        cin >> a[i];
        occ[i+1] = 1e9;
    }
    dp[n-1] = 1;
    if(a[n-1] > 0) occ[a[n-1]] = n-1;
    for (int i = n - 2; i >= 0; i--){
      if( a[i] > 0){
        dp[i] = 1 + dp[i+1];
        occ[a[i]] = i;
      }else
      dp[i] = min(occ[-a[i]] - i ,1 + dp[i+1]);
        
    }
    for (int i = 0; i < n; i++) cout << dp[i] << " ";
}