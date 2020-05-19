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
int dp[3][MAXN];
int suf[MAXN];
int pref[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += (s[i] == '1');
        int ans = sum;
        for(int i = 0; i < k; i++){
            int d = 0;
            for(int j = i; j < n; j += k){
                if(s[j] == '1') 
                    d++;
                else --d;
                d = max(d,0);
                ans = min(ans,sum - d);
            }
        }
        cout << ans << endl;
    }
}