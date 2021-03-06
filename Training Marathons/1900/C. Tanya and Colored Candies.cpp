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
int const MAXN = 50 + 9;
int a[MAXN];
string col;
string ch = "RGB";
int dp[55][2005][55][4];
int n;
int solve(int pos, int k, int last, int c){
    if(k <= 0) return 0;
    int & ret = dp[pos][k][last][c];
    if( ~ ret) return ret;
    ret = 1e9;
    if(a[pos] > last && col[pos] != c) ret = min(ret,solve(pos,k - a[pos],a[pos],col[pos]));
    if(pos >= 1) ret = min(ret,1 + solve(pos - 1,k,last,c));
    if(pos + 1 < n) ret = min(ret,1 + solve(pos + 1,k,last,c));
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int s, k;
    cin >> n >> s >> k;
    s--;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> col;
    for(auto & c : col){
        for(int j = 0; j < 3;j++)
            if(c == ch[j]) c = j;
    }
    memset(dp,-1,sizeof(dp));
    int ans = solve(s,k,0,3);
    if(ans == 1e9) ans = -1;
    cout << ans << endl;
}