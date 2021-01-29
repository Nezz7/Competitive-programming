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
map<string,int> patern;
string s[MAXN];
int ans[MAXN];
int b[MAXN];
vector<int> g[MAXN];
int col[MAXN];
bool cycle = false;
vector<int> topo;
void dfs(int node){
    col[node] = 1;
    for(auto child : g[node]){
        if(col[child] == 0) dfs(child);
        else if(col[child] == 1) cycle = true;
    }
    col[node] = 2;
    topo.push_back(node);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++){
        string p;
        cin >> p;
        patern[p] = i + 1;
    }

    for(int i = 0; i < m; i++){
        int x;
        cin >> s[i] >> x;
        b[i] = x;
        bool match = false;
        for(int j = 0; j < (1 << 4); j++){
            string ss = s[i];
            for(int k = 0; k < 4; k++){
                int b = !!(j & (1 << k));
                if(b) ss[k] = '_';
            }
            if(patern.count(ss)){
                int u = patern[ss];
                if(u != x) g[x].push_back(u);
                else match = true;
            }
        }
        if(!match) cycle = true;
    }
    for(int i = 0; i < n; i++){
        if(col[i + 1] == 0) dfs(i + 1);
    }
    
    if(!cycle){
        cout << "YES" << endl;
        reverse(all(topo));
        for(auto u : topo) cout << u << " ";
    }else  cout << "NO" << endl;

}