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
int out[MAXN];
int cur;
vector<vector<int>> g;
void dfs(int node){
    out[node] = cur;
    for(auto child : g[node]){
        if(!out[child]) dfs(child);
    }
}
void get(int i){
    if (i <= 26){
        cout << (char) ('A'+ i - 1) << ' ';
        return ;
    }
    i -= 26;
    cout << (char) ('Z');
    cout << (char) ('a'+ i - 1) << ' ';
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, k;
    cin >> n >> k;
    g.resize(n + 1);
    for(int i = 0; i < n - k + 1; i++){
        string s;
        cin >> s;
        if(s == "NO"){
            g[i].pb(i + k - 1);
            g[i + k - 1].pb(i + k - 1);
        }
    }
    for(int i = 0; i < n; i++) 
        if(!out[i]){
            cur++;
            dfs(i);
        }
    for(int i = 0; i < n; i++) 
        get(out[i]);
}