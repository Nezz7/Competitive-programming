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
        int n, x, m;
        cin >> n >> x >> m;
        int l = x, r = x;
        for(int i = 0; i < m; i++){
            int u, v;
            cin >> u >> v;
            if(r < u or v < l) continue;
            l = min(u,l);
            r = max(v,r);
        }
        cout << r - l + 1 << endl;
    }
}