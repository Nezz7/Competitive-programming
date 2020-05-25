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
vector<int> in[MAXN];
int l[MAXN], r[MAXN];
int tim[MAXN],used[MAXN];
vector<vector<int>> g;
int e;
int cur;
void dfs(int node){
    used[node] = 1;
    for(auto child : g[node]){
        if(!used[child]) dfs(child);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n + 1);
    for(int i = 1; i <= n; i++){
        cin >> l[i] >> r[i];
        in[l[i]].pb(i);
        in[r[i] + 1].pb(-i);
    }
    set<pair<int,int>> st;
    for(int i = 1; i < MAXN; i++){
        for(auto x : in[i]){
            if(x < 0){
                auto it = st.upper_bound({tim[-x],-x});
                while(it != st.end()){
                    g[-x].pb(it->second);
                    g[it->second].pb(-x);
                    e++;
                    if(e == n){
                        cout << "NO";
                        return 0;
                    }
                    it++;
                }
                st.erase({tim[-x],-x});
            }
        }
        for(auto x : in[i]){
            if(x > 0){
                tim[x] = ++cur;
                st.insert({tim[x],x});
            }
        }
    }
    if (e != n - 1) cout << "NO" << endl;
    else {
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(!used[i]){
                cnt++;
                dfs(i);

            }
        }
        if(cnt == 1) cout <<"YES"<< endl;
        else cout << "NO" << endl;
    }
}