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
int const MAXN = 500+1;
int dp[501][501];
int pref[MAXN][MAXN];
int suf[MAXN][MAXN];
void solve(int n) { 
  for (int line = 0; line < n; line++) { 
    for (int i = 0; i <= line; i++) { 
        if (line == i || i == 0) 
            dp[line][i] = 1;
        else
            dp[line][i] = dp[line - 1][i - 1] +   dp[line - 1][i]; 
    } 
    } 
} 
void go (int x, int y, int n){
        cout << x + 1 << " " << y + 1 << endl;
        if (n == 0) return;
        // go down
        if(pref[x+1][y + 1] <= n){
            go(x+1,y+1, n - dp[x+1][y+1]);
            return;
        }
        if (pref[x + 1][y] <= n){
            go(x+1,y, n - dp[x+1][y]);
            return;
        }
        if(y > 0 && pref[x][y-1] <= n){
            go(x,y-1,n - dp[x][y-1]);
            return;
        }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    solve (MAXN);
    for (int i = 0; i < MAXN; i++){
        pref[i][0] = dp[i][0];
        for (int j = 1; j <= i; j++){
            pref[i][j] += pref[i][j - 1] + dp[i][j];
        }
    }
    int T;
    cin >> T;
    int cc = 0;
    while (T--){
        cc++;
        int n;
        cin >> n;
        cout << "Case #"  << cc << ": " << endl;
        go (0,0,n - 1); 
    }

    
}
