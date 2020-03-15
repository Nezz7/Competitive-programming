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
LL k;
vector <LL> v;
void get (LL x){
    if (x > 1) 
        get(x/k);
    v.pb(x % k);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL n;
        cin >> n >> k;
        vector<vector<LL>> g (n);
        LL a[n];
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < n; i++){
            v.clear();
            get(a[i]);
            reverse(all(v));
            g[i] = v;
        }
        bool cond = true;
        for(int j = 0; j < 65; j++){
            int cur = 0;
            for (int i = 0; i < n; i++)
                if (j < g[i].size()){
                    if (g[i][j] == 1) cur ++;
                    if (g[i][j] > 1) cur  = 5;
                }
            if (cur > 1) cond = false;
        }
        if (cond){
            cout  << "YES" << endl;
        }else cout << "NO" << endl;
        g.clear();
    }
}

