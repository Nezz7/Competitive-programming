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
int l[MAXN];
int up[MAXN][30];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, q;
    cin >> n >> q;
    for(int i = 0; i < n; i++){
        int u, v;
        cin >> u >> v;
        l[u] = max(l[u],v);
    }
    int mx = 0;
    for(int i = 0; i < MAXN; i++){
        mx = max(mx, l[i]);
        up[i][0] = mx;
    }
    for(int j = 1; j < 19; j++)
        for(int i = 0; i < MAXN; i++)
            up[i][j] = up[up[i][j - 1]][j - 1];
    while(q--){
        int a, b;
        cin >> a >> b;
        int ans = 0;
        for(int i = 18; i >= 0; i--){
            if(up[a][i] < b){
                ans |= (1 << i);
                a = up[a][i];
            }
        }
        a = up[a][0];
        ans++;
        if(a < b) cout << - 1 << endl;
        else cout << ans << endl;
    }
}