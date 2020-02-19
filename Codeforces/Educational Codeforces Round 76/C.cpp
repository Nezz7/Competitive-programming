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
int last[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n; 
        for (int i = 0; i <= n; i++){
            last[i] =-1;
        }
        int ans = 1e9;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            if (last[x] != -1) ans = min(ans,i-last[x] + 1);
            last[x] = i;
        }
        if (ans == 1e9) cout << -1 << endl;
        else cout << ans << endl;
    }
}