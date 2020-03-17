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
LL MOD = 1e9 + 7;
int vis [MAXN];
int visr [MAXN];
int occ[MAXN];
inline int power(int x, int n){
	if(n == 0) return 1;
	int y = power(x, n>>1);
	y = ((LL)y*y) %MOD;
	if(n&1) y = ((LL)y*x) %MOD;
	return y;
}
vector<vector<int>> g;
vector<vector<int>> gr;
int cc;
int nbr;
void dfs (int node){
    nbr++;
    vis[node] = 1;
    for (auto child : g[node]){
        if (!vis[child]){
            dfs(child);
        }
    }
}
void dfsr (int node){
    nbr++;
    visr[node] = 1;
    for (auto child : gr[node]){
        if (!visr[child]){
            dfsr(child);
        }
    }
}
vector<int> cycle;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    int c = 0;
    while(cin >> n >> m){
        g.clear();
        gr.clear();
        g.resize(n);
        gr.resize(m);
        cycle.clear();
        memset(occ,0,sizeof occ);
        memset(vis,0,sizeof occ);
        memset(visr,0,sizeof occ);
        c ++;
        cc = 0;
        for (int i  = 0; i < n; i++){
            int v;
            cin >> v;
            vis[i] = 0;
            g[v].pb(i);
            g[i].pb(v);
        }
        for (int i = 0; i < m;i++){
            int x;
            cin >> x;
            gr[x].pb(i);
            gr[i].pb(x);
        }
        for (int i = 0; i < n; i++){
            if (!vis [i]){
                nbr = 0;
                dfs(i);
                cycle.pb(nbr);
                cc++;
            }
        }
        for (int i = 0; i < m; i++){
            if (!visr [i]){
                nbr = 0;
                dfsr(i);
                occ[nbr]++;
            }
        }
        LL ans = 1;
        for(auto cur : cycle){
            LL cur_ans = 0;
            for (LL i = 1; i*i <= cur; i++){
                if (cur % i == 0){
                    cur_ans += (1LL* occ[i]* i) % MOD;
                    cur_ans%= MOD;
                    if (cur/i != i){
                        cur_ans +=  (1LL* occ[cur/i]* cur/i) % MOD;
                        cur_ans%= MOD;
                    }
                }
            }
            ans *= cur_ans;
            ans %= MOD;

        }
        cout <<"Case #"<< c <<": "<< ans << endl;
 
    }
}