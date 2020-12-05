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
vector<int> g[MAXN];
int b[MAXN];
string op[MAXN];
void dfs(int node){
    for(auto child : g[node]){
        dfs(child);
    }
    if(op[node] == "AND")
        b[node] = b[g[node][0]] & b[g[node][1]];
    else if (op[node] == "OR")
        b[node] = b[g[node][0]] | b[g[node][1]];
    else if (op[node] == "XOR")
        b[node] = b[g[node][0]] ^ b[g[node][1]];
    else if(op[node] == "NOT")
        b[node] = !b[g[node][0]];
}
bool impact[MAXN];
void dfs2(int node){
    int left = 0, right = 0;
    if(op[node] == "AND"){
       left = (b[g[node][0]] ^ 1) & b[g[node][1]];
       right = (b[g[node][1]] ^ 1) & b[g[node][0]];
    }else if (op[node] == "OR"){
       left = (b[g[node][0]] ^ 1) | b[g[node][1]];
       right = (b[g[node][1]] ^ 1) | b[g[node][0]];
    }else if (op[node] == "XOR"){
       left = (b[g[node][0]] ^ 1) ^ b[g[node][1]];
       right = (b[g[node][1]] ^ 1) ^ b[g[node][0]];
    }else if(op[node] == "NOT")
       left = !(b[g[node][0]] ^ 1);
    else {
        return;
    }
    if(left  != b[node] && impact[node]) impact[g[node][0]] = true;
    if(right != b[node] && impact[node] && op[node] != "NOT") impact[g[node][1]] = true;

    for(auto child : g[node]){
        dfs2(child);
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> op[i];
        if(op[i] == "IN") cin >> b[i];
        else if (op[i] == "NOT"){
            int x;
            cin >> x;
            g[i].pb(x);
        }else {
            int x, y;
            cin >> x >> y;
            g[i].pb(x);
            g[i].pb(y);
        }
    }
    dfs(1);
    impact[1] = true;
    dfs2(1);
    for(int i = 1; i <= n; i++){
        if(op[i] == "IN"){
            if(impact[i]) cout << (b[1] ^ 1);
            else cout << b[1];
        }
    }
}