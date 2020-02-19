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
int best [MAXN];
int p[MAXN],s[MAXN],a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        for (int i = 0; i <= n ; i++) best[i] = 0;
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        int m;
        cin >> m;
        for(int i = 0; i < m; i++){
            cin >> p[i] >> s[i];
            best[s[i]] = max(best[s[i]],p[i]);
        }
        for (int i = n - 1; i >= 0; i--)
            best[i] = max(best[i],best[i+1]);
        int cur = 0;
        int ans = 0;
        while (cur < n){
            if (best[0] < a[cur]) break;
            int mx = 0;
            int x = 0;
            for (int i = 1; i <= n; i++){
                mx = max(mx,a[cur+i-1]);
                if (best[i] >= mx) x = i;
                else break;
            }
            cur +=x;
            ans++;
        }
        if (cur >= n) cout << ans << endl;
        else cout << -1 << endl;
    }
}