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
int const MAXN = 500 + 9;
int dp[MAXN][MAXN];
int cnt[MAXN][MAXN];
string s;
int ans = 1e9;
int cur;
int n;
void track(){
    string ret ="";
    int j = n -1 ;
    bool first = true;
    for(int i = n -1; i >= 0; i--){
        int len = j - i + 1;
        if(!cur) break;
        if(ans == cnt[i][len + i - 1] + dp[i][cur - 1]){
            cur--;
            ans -= cnt[i][len + i - 1];
            string ch = s.substr(i,len);
            int l = sz(ch);
            for(int k = 0; k < l / 2; k++){
                if(ch[k] != ch[l - 1 - k]) ch[k] = ch[l - 1 - k]; 
            }
            j = i - 1;
            if (!first)
                ret = ch + "+" + ret;
            else ret = ch,first = false;
        }
    }
    int i = 0;
    int len = j + 1;
    string ch = s.substr(i,len);
    int l = sz(ch);
    for(int k = 0; k < l / 2; k++){
        if(ch[k] != ch[l - 1 - k]) ch[k] = ch[l - 1 - k]; 
    }
    if(sz(ch) == 0){
        cout << ret;
        return;
    }
    if (!first)
        ret = ch + "+" + ret;
    else ret = ch,first = false;
    cout << ret;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int k;
    cin >> s >> k;
    n = s.size();
    for (int i = 0; i < n; i++)
        for(int j = i; j < n; j++){
            int len = j - i + 1;
            for(int k = 0; k < len/2; k++){
                if(s[i + k] != s[j - k]) cnt[i][j]++;
            } 
        }   
    for(int i = 0; i <= n; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = 1e9;
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            for(int len = 1; i + len <= n; len++)
                dp[i + len][j + 1] = min (dp[i + len][j + 1], cnt[i][i + len - 1] + dp[i][j]);
        }
    }
    for(int i = 0; i <= k; i++){
        ans = min(ans, dp[n][i]);
        if(dp[n][i] == ans) cur = i;
    }
    cout << ans << endl;
    track();

}   