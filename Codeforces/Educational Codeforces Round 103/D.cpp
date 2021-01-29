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
int const MAXN = 2e6 + 9;
string s;
int n;
int dp[MAXN][3], dp1[MAXN][3];
int solve(int i, int last){
    if(i == n) return 0;
    int & ret = dp[i][last];
    if(ret != -1) return ret;
    ret = 0;
    if(last == 0 && s[i] == 'R'){
        ret = max(ret, 1 + solve(i + 1, 1));
    }
    if(last == 1 && s[i] == 'L')
        ret = max(ret, 1 + solve(i + 1, 0));
    return ret;
}
int solve1(int i, int last){
    if(i == 0) return 0;
    int & ret = dp1[i][last];
    if(ret != -1) return ret;
    ret = 0;
    if(last == 0 && s[i - 1] == 'L'){
        ret = max(ret, 1 + solve1(i - 1, 1));
    }
    if(last == 1 && s[i - 1] == 'R')
        ret = max(ret, 1 + solve1(i - 1, 0));
    return ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> s;
        for(int i = 0; i < n + 9; i++){
            dp[i][0] = dp[i][1] = -1;
            dp1[i][0] = dp1[i][1] = -1;
        }
        for(int i = 0; i <= n; i++){
            cout << solve1(i, 0) + solve(i, 0) + 1 << " ";
        }
        cout << endl;
    }
}