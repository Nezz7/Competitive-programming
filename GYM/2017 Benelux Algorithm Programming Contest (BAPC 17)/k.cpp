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
vector<vector<int>>g;
vector<int> out;
int vis[MAXN];
void impo (){
    cout << "impossible";
    exit(0);
}
void dfs(int node){
    vis[node] = true;
    for(auto child : g[node]){
        if(!vis[child] ) {
            dfs(child);
        }
    }
    out.pb(node);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    if (n == 1){
        cout << 0;
        return 0;
    }
    g.resize(n);
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        for (int j = 0; j < n; j++){
            if(s[j] == '1'){
                g[i].pb(j);
            }
        }
    }
    dfs(0);
    if (sz(out) != n) impo();
    for(auto cur : out){
        cout << cur << ' ';
    }
}