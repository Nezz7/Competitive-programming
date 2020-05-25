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
int const MAXN = 2000 + 9;
int dp[MAXN][MAXN];
int zero[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    zero[0] = 0;
    for(int i = 0; i < n; i++){
        zero[i + 1] = zero[i] + (s[i] == '0');
    }
    for(int l = 0; l < n; l++){
        dp[l][l] = 1;
        for(int r = l + 1; r < n; r++){
            if(s[r] == '1') dp[l][r] = dp[l][r - 1] + 1;
            else dp[l][r] = max(dp[l][r - 1],zero[r + 1] - zero[l]);
        }
    }
    string ans = s;
    for(int i = 0; i < n; i++){
        if(s[i] == '0') continue;
        bool cond = true;
        for(int j =  i - 1; j >= 0; j--){
            int last = dp[j][i];
            int cur = max(dp[j][i - 1],zero[i + 1] - zero[j] + 1);
            /*cout <<'('<<  j << '-' << i << ") : ";
            cout << last << ' ' << cur << endl;*/
            if(cur != last) cond = false;
        }
        for(int j = i + 1; j < n; j++){
            int last = dp[i][j];
            int cur = max(dp[i][j - 1],dp[i + 1][j]+ 1);
            /*cout <<'('<<  i << '-' << j << ") : ";
            cout << last << ' ' << cur << endl;*/
            if(cur != last) cond = false;
        }
        if(!cond) continue;
        for(int j = i; j < n; j++) zero[j + 1]++;
        s[i] = '0';
    }
    cout << s;
}