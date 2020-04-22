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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        LL ans = 0;
        for(int j = 0; j < (k + 1)/2; j++){
            map<char,int> mp;
            int mx = 0;
            int cnt = 0;
            for(int i = 0; i < n; i+=k){
                int l = i + j, r = i + k - 1 - j;
                if(l == r){
                    cnt++;
                    mp[s[l]]++;
                    mx = max(mp[s[l]],mx);
                }else {
                    cnt += 2;
                    mp[s[l]]++;
                    mp[s[r]]++;
                    mx = max(mp[s[l]],mx);
                    mx = max(mp[s[r]],mx);
                }
            }
            ans += cnt - mx;
        }
        cout << ans << endl;
    }
}