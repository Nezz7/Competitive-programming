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
int const MAXN = 100 + 9;

//O(V²E)
    vector< int > g[MAXN];
struct hopcroft_karp{
    int const INF = 1e9;
    int n, m, match[MAXN], dist[MAXN];
    hopcroft_karp(int _n, int _m){
        n = _n;
        m = _m;
    }
    bool bfs() {
        int i, u, v, len;
        queue< int > Q;
        for(i=1; i<=n; i++) {
            if(match[i]==0) {
                dist[i] = 0;
                Q.push(i);
            }
            else dist[i] = INF;
        }
        dist[0] = INF;
        while(!Q.empty()) {
            u = Q.front(); Q.pop();
            if(u!=0) {
                len = g[u].size();
                for(i=0; i<len; i++) {
                    v = g[u][i];
                    if(dist[match[v]]==INF) {
                        dist[match[v]] = dist[u] + 1;
                        Q.push(match[v]);
                    }
                }
            }
        }
        return (dist[0]!=INF);
    }
 
    bool dfs(int u) {
        int i, v, len;
        if(u!=0) {
            len = g[u].size();
            for(i=0; i<len; i++) {
                v = g[u][i];
                if(dist[match[v]]==dist[u]+1) {
                    if(dfs(match[v])) {
                        match[v] = u;
                        match[u] = v;
                        return true;
                    }
                }
            }
            dist[u] = INF;
            return false;
        }
        return true;
    }
 
    int solve() {
        int matching = 0, i;
        memset(match, 0, sizeof match);
        while(bfs())
            for(i=1; i<=n; i++)
                if(match[i]==0 && dfs(i))
                    matching++;
        return matching;
    }
 
 
};
char a[MAXN][MAXN];
int n, m;
bool isValid(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m;
}
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int col[MAXN * MAXN];
int getId(int i, int j){
    return i * m + j;
}
void dfs(int i, int j,int par, char c){

    a[i][j] ='X';
    for(int k = 0; k < 4; k++){
        int x = i + dx[k];
        int y = j + dy[k];
        if(isValid(x,y) && a[x][y] == c){
            dfs(x, y, getId(i,j), c);
        }
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> a[i][j];
        }
    }

    // transform L neighbors C to W
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L')
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                if(isValid(x,y) && a[x][y] =='C') a[x][y] = 'W';
            }
        }
    }
    int nodes = 0;
    // count C
     for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            nodes += a[i][j] == 'C';
    hopcroft_karp

    // Generate bipartite graph
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'C'){
                ans++;
                if((i + j) & 1){
                    d.add_edge(d.s, getId(i,j),1);
                    for(int k = 0; k < 4; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(isValid(x,y) && a[x][y] =='C'){
                            d.add_edge(getId(i,j), getId(x,y),1);
                        }
                    }
                }else {
                    d.add_edge(getId(i,j), d.t ,1);
                    for(int k = 0; k < 4; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        if(isValid(x,y) && a[x][y] =='C'){
                            d.add_edge(getId(x,y), getId(i,j),1);
                        }
                    }
                }
            }
        }
    }
    
    ans -= d.flow();

    // count CC of L
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(a[i][j] == 'L') dfs(i,j,-1,'L'), ans++;
        }
    }
    cout << ans << endl;
}