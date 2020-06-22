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
LL s[MAXN],a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL n,t;
        cin >> n >> t;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        s[0] = 0;
        for (int i = 0; i < n; i++){
            s[i+1] = s[i] + a[i];
        }
        int ans = 0, mx = -1e9;
        if (s[n] <= t) ans = 0,mx = n;
        for (int i = 0; i < n; i++){
            if(s[i] > t) continue;
            auto cur = upper_bound(s+1,s+n+1,a[i]+ t) - s-1;
            cur--;
            if (mx < cur){
                mx = cur;
                ans = i+1;
            }
        }
        cout << ans << endl;
    }
}