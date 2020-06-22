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
int const MAXN = 5000+ 9;
int pref[MAXN], suff[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        pref[0] = 0;
        suff[n] = 0;
        for(int i = 0; i < n; i++){
            pref[i + 1] = pref[i] + (s[i] == '1');
        }
        for(int i = n - 1; i >= 0; i--){
            suff[i] = suff[i + 1] + (s[i] == '1');
        }
        int ans = 1e5;
        for(int i = 0; i < n; i++){
            // 1 0
            int onep = pref[i + 1];
            int zerop = i + 1 - pref[i + 1];
            int ones = suff[i + 1];
            int zeros = (n - i - 1) - suff[i + 1];
            ans = min(ans,zerop + ones);
            ans = min(ans,onep + zeros);
        }
        cout << ans << endl;
    }
}