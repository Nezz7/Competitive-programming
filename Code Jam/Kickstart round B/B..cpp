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
int const MAXN = 50 + 9;
char a[MAXN][MAXN];
int vis[MAXN][MAXN];
int n, m;
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
bool valid(int i, int j){
    return i >= 0 && i < n && j >= 0 && j < m;
}
int nbr;
int mny, mxy;
void dfs(int i, int j){
    mny = min(j,mny);
    mxy = max(j,mxy);
    vis[i][j] = true;
    nbr++;
    for(int k = 0; k < 4; k++){
        int x = i + dx[k]; 
        int y = j + dy[k]; 
        if(valid(x,y) && !vis[x][y] && a[x][y] == a[i][j])
            dfs(x,y);
    }
}
vector<char> out;
vector<vector<int>> g;
int col[30];
void print(int node){
    col[node] = 1;
    for(auto child : g[node]){
        if(!col[child]) print(child);
    }
    out.pb(node + 'A');
}
void solve(int t){
    cin >> n >> m;
    for(int i = 0; i < 30; i++) col [i] = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++){
            vis[i][j] = 0;
            cin >> a[i][j];
        }
    }
    nbr = 0;
    bool cond = true;
    int start = -1;
    out.clear();
    set<char> st;
    for(int j = n - 1; j >= 0; j--){
         for(int i = 0; i < m; i++){
            if(!vis[j][i]) {
                st.insert(a[j][i]);
                mny = 1e9;
                mxy = 0;
                dfs(j , i);
            }
            for(int x = 0; x < n; x++){
                for(int y = 0; y < m; y++){
                    if(a[x][y] == a[j][i] && !vis[x][y]) cond = false;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool first = false;
            for(int k = i + 1;  k < n; k++){
                if(a[i][j] != a[k][j]) first = true;
                if(a[i][j] == a[k][j] && first) cond = false;

            }
        }
    }
    g = vector<vector<int>>(26);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            bool first = false;
            for(int k = i + 1;  k < n; k++){
                if(a[i][j] != a[k][j]){
                    g[a[k][j] - 'A'].pb(a[i][j] - 'A');
                }

            }
        }
    }
    for(int i = 0; i < 26; i++){
        if(!col[i] && sz(g[i])) print(i);
    }
    reverse(all(out));
    for(auto x : st) if(!col[x - 'A']) out.pb(x);
    cout << "Case #"<< t <<": ";
    if (nbr != n * m or !cond){
         cout <<  -1 << endl; 
        return;
    }
    for(auto x : out) cout << x;
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int cc = 0;
   for(int t = 1; t <= T; t++){
       solve(t);
   }
}