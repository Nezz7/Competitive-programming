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
int const MAXN = 2e5 + 9;
vector<int> g[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++) g[i].clear();
        for(int i = 0; i < n; i++){
            int m,p;
            cin >> m >> p;
            g[m].pb(p);
        }
        int pref = n;
        LL ans = 0;
        int cur = 0;
        multiset<int> st;
        for(int i = n - 1; i >= 0; i--){
            pref -= sz(g[i]);
            for(auto x : g[i]) st.insert(x);
            int need = 0;
            if(pref + cur < i) need = i - pref - cur, cur += need;
            while(need){
                need--;
                ans += *st.begin();
                st.erase(st.begin());
            }
        }
        cout << ans << endl;
    }
}