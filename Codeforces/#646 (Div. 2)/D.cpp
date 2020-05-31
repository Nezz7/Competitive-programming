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
int const MAXN = 5000 + 9;
int n, k;
int sz[MAXN];
vector<vector<int>> g;
int ask (int x){
    cout << "? " << sz[x + 1] << ' ';
    for(int i = 0; i <= x; i++){
        for(auto child : g[i]) cout << child << ' ';
    }
    cout << endl;
    cout.flush();
    int a;
    cin >> a;
    return a;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        g.resize(k);
        for(int i = 0; i < k; i++) g[i].clear();
        sz[0] = 0;
        for(int i = 0; i < k; i++){
            int m;
            cin >> m;
            for(int j = 0; j < m; j++){
                int x;
                cin >> x;
                g[i].pb(x);
            }
            sz[i + 1] = sz[i] + m;
        }
        
        cout << "? " << n << ' ';
        for(int i = 1; i <= n; i++)
            cout << i << ' ';
        cout << endl;
        cout.flush();
        int mx;
        cin >> mx;
        int low = 0, hi = k - 1;
        int to = -1;
        while(low <= hi){
            int mid = (low + hi + 1) / 2;
            if(ask(mid) == mx){
                to = mid;
                hi = mid - 1;
            }else low = mid + 1;
        }
        if(to != -1){
            cout << "? " << n - sz(g[to]) << ' ';
            set<int> st;
            for(auto cur : g[to]) st.insert(cur);
            for(int i = 1; i <= n; i++) if(!st.count(i)) cout << i << ' ';
            cout << endl;
            cout.flush();
            int x;
            cin >> x;
            cout << "! ";
            for(int i = 0; i < k; i++){
                if(i == to) cout << x << ' ';
                else cout << mx << ' ';
            }
            cout << endl;
            cout.flush();
        }else {
            cout << "! ";
             for(int i = 0; i < k; i++){
                cout << mx << ' ';
            }
            cout << endl;
            cout.flush();
        }
        string s;
        cin >> s;
    }
}