#include <bits/stdc++.h>
#define f first
#define s second
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
vector<vector<int>> g;
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        g.clear();
        g.resize(n+1);
        memset(a,0,sizeof(a[0]) * (n+2));
        for (int i = 0; i <n; i++){
            int k;
            cin >> k;
            for(int j = 0; j < k; j++){
                int x;
                cin >> x;
                g[i].pb(x);
            }
            sort(all(g[i]));
        }
        vector<int> ans;
        for (int i = 0; i < n; i++){
            bool cond = false;
            for (auto x : g[i]){
                if(!a[x]){
                    cond = true;
                    a[x] = 1;
                    break;
                }
            }
            if(!cond){
                ans.pb(i+1);
            }
        }
        if(sz(ans) == 0){
            cout << "OPTIMAL" << endl;
            continue;
        }
        cout << "IMPROVE" << endl;
        cout << ans[0] << " ";
        for(int i = 1; i <= n; i++){
            if(!a[i]){
                cout << i << endl;
                break;
            }
        }
    }
}