#include <bits/stdc++.h>
#define LL long long int
using namespace std;
LL const MOD = 1e9+7;
LL mypow (LL a, LL b){
    if (b == 0) return 1;
    LL x = mypow (a, b / 2);
    if (b % 2 ){
        return ( (x * x) % MOD * a) % MOD;
    }
    return (x * x) % MOD;
}
LL n , m ,k;
vector <vector <int>> adj;
void build_graph (LL n , LL k){
    for (int i = 0 ; i <= n - k ; i++){
        for (int j = i; j < i + (k / 2) ; j++){
             int u = j;
             int v = k - 1 - (j - i) + i ;
             if (u != v){
                adj[u] . push_back(v);
                adj[v] . push_back(u);
             }
        }
    }
}
int vis [5000];
void DFS (int node){
    vis[node] = 1;
    for (auto child : adj[node]){
        if (!vis [child]) DFS (child);
    }
}
int main (){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    cin >> n >> m >> k;
    adj.resize( n + 1 );
    build_graph ( n , k );
    LL cc = 0;
    for (int i = 0 ; i < n ;i++){
        if (! vis [i]) DFS (i), cc++;
    }
    cout<< mypow (m, cc) << "\n";
}
