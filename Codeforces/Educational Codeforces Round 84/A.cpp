#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 3000 + 9;
int dp[MAXN][MAXN];
int solve(int i , int j){
    cout << i << " " << j << endl;
    if (i > j) return 0;
    if ( i == j) return 1;
    
    int & ret = dp[i][j];
    if (ret != -1) return ret;
    ret = 0;
    for(int k = i; k < j; k++){
        cout << i << " " << k << " " << j << endl;
    ret += solve(i,k) + solve(k+1,j);
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    memset(dp,-1,sizeof dp);
        cout << solve(1,3);
    /*
    for(int i = 1; i < 10; i++){
        cout << solve(1,i) << endl;
    }*/
    /*int T;
    cin >> T;
    while(T--){
        LL n,k;
        cin >> n >> k;
        if(n%2 != k%2 or k*k > n){
            cout << "NO" << endl;
        }else cout << "YES"<< endl;
    }*/
}