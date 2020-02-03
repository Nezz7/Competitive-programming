#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
int dp[MAXN][3];
int a[MAXN][3];
int n;
LL ans ;
int solve (int i, int last){
    if (i == n) return 0;
    int & ret = dp[i][last];
    if (ret != -1) return ret;
    ret = 1e9;
    if (a[i][0] == last) ret = min(ret,solve(i+1,a[i][1]));
    if (last == a[i][1]) ret = min(ret,1+solve(i+1,a[i][0]));
    return ret;
}
void print (int i , int last){
    if (i == n) return ;
    if (a[i][0] == last && ans ==solve(i+1,a[i][1])) print(i+1,a[i][1]);
    else if (last == a[i][1] && ans == 1 + solve(i+1,a[i][0])){
             ans --;
             cout << i+1 << " ";
             print(i+1,a[i][0]);
             }

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        cin >> n;
        ans = 0;
        for (int i = 0; i < n;i++){
            string s;
            cin >> s;
            int sz = s.size();
            a[i][0] = s[0] - '0';
            a[i][1] = s[sz - 1] - '0';
        }
        for (int i = 0; i <= n; i++){
            for (int j = 0; j <3; j++)
                dp[i][j] = -1;
        }
        ans = min(solve(0,0),solve(0,1));
        if (ans == 1e9) cout << "-1\n";
        else{ cout << ans << "\n";
            if (ans == solve(0,0)) print(0,0);
            else if (ans == solve(0,1))print(0,1);
            cout << "\n";
        }
    }

}
