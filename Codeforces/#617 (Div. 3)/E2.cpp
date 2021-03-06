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
int dp[MAXN],pref[26];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) 
        dp[i] = 1;
    int ans = 0;
    for (int i = 0; i < n; i++){
        int cur = 0;
        for (int j = s[i] - 'a' + 1; j < 26; j++){
            cur = max(pref[j],cur);
        }
        dp[i] = cur + 1;
        pref[s[i] - 'a' ] = max(pref[s[i]- 'a'],dp[i]);
        ans = max(dp[i],ans);
    }
    cout << ans << endl;
    for (int i = 0; i < n; i++) cout << dp[i] << " ";
}