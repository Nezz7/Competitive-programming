#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 1e5 + 9;
LL a[MAXN];
vector <int> bits[65];
vector <set <int> > adj;
int vis[MAXN];
int ans = INT_MAX;
void DFS (int node, int p ,int path){
    vis [node] = path;
    for (auto child : adj [node]){
        if (child == p) continue;
        if (! vis [child]) DFS (child, node, 1 + path );
        else ans = min (ans, path + vis [child] );
    }
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    adj = vector < set<int> > (n+1) ;
    for (int i = 0; i < n; i++){
        cin >> a [i];
        for (int j = 0; j < 64; j++){
            LL bit = (a[i]&(1LL<<j));

            if (bit) {
                    for (auto cur : bits[j]){
                        adj[i].insert(cur);
                        adj[cur].insert(i);
                    }
                    bits[j].push_back(i);
            }

        }
    }
    for (int i=0; i <n ; i++){
        if (!vis[i]) DFS(i,i,1);
    }
    if (ans == INT_MAX) cout << -1 << "\n";
    else cout << ans - 1 << "\n";

}
