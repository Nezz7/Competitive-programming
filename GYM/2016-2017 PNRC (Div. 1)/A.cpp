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
int const MAXN = 100 + 9;
int dp[MAXN][MAXN];
int n, m;
string a, b = "abcdefghijklmnopqrstuvwxyz";
int solve(int i, int j){
    if(j == m) return 0;
    if(i == n) return m - j;
    int & ret = dp[i][j];
    if(ret != -1) return ret;
    ret = 1e9;
    if(a[i] == b[j]){
        ret = solve(i + 1, j + 1);
    }
    return ret = min(1 + solve(i, j + 1), min(ret, solve(i + 1, j)));
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> a;
    n = a.size();
    m = b.size();
    memset(dp, -1, sizeof dp);
    cout << solve(0,0);
}