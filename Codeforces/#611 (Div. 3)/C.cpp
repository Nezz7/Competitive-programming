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
vector<vector<int>> g;
int in [MAXN];
int a [MAXN],last;
void dfs (int node){
    last = node;
    for (auto child : g[node])
        dfs(child);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    g.resize(n+1);
    for(int i= 0; i <n; i++){
        cin >> a[i];
        if (a[i])
        g[i+1].pb(a[i]);
        in[a[i]]++;
    }
    vector<int> out;
    bool cond = false;
    for (int i = 0; i < n; i++){
        if (in[i+1] == 0 && g[i+1].size() == 0){
            out.pb(i+1);
        }
    }
    if (sz(out) == 0) cond = true;
    for (int i = 1; i <= n; i++){
        if (in[i] == 0 && g[i].size()){
            dfs(i);
            if (cond == false){
                a[last - 1] = out[0];
                for (int i = 1; i  < sz(out); i++){
                    a[out[i - 1] - 1] = out[i];
                }
                a[out[sz(out) - 1] - 1] = i;
                cond = true;
            }else a[last - 1] = i;
        }
    }
    if (cond == false){
        for (int i = 1; i  < sz(out); i++){
                    a[out[i - 1] - 1] = out[i];
        }
        a[out[sz(out) - 1] - 1] = out[0];
    }
    for (int i = 0; i < n; i++) cout << a[i] << " ";
}