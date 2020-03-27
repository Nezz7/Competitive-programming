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
int const MAXN = 2e5 + 9;
int p[MAXN],c[MAXN];
int vis[MAXN];
vector<int> _div[MAXN];
vector<int> nbr;
vector<int> cycle;
void dfs(int node){
    vis[node] = 1;
    cycle.pb(node);
    if(!vis[p[node]]){
        dfs(p[node]);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for(int i = 1; i < MAXN; i++){
        for(int j = i; j < MAXN; j+=i){
            _div[j].pb(i);
        }
    }
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        memset(vis,0,sizeof(vis[0]) * (n+2));
        for(int i = 1; i <= n; i++)
            cin >> p[i];
        for(int i = 1; i <= n; i++)
            cin >> c[i];
        int ans = n;
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                cycle.clear();
                dfs(i);
                int sz = sz(cycle);
                for(auto x : _div[sz]){
                    for(int i = 0; i < x; i++){
                        bool good = 1;
                        for(int nxt = (i+x)%sz; nxt!= i; nxt = (nxt+x)%sz){
                            good &= (c[cycle[nxt]] == c[cycle[i]]);
                        }
                        if(good){
                            ans = min(ans,x);
                        }
                    }
                }
            }
        }
        cout <<  ans << endl;
    }
}