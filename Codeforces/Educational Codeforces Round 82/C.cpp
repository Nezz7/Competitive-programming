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
set<int> g[26];
int vis[26];
bool cycle;
vector<int> out;
void dfs (int node,int par){
    vis[node] = 1;
    out.push_back(node);
    for (auto child : g[node]){
        if (!vis[child]) dfs(child,node);
        else if (child != par) cycle = true;
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        string s;
        cin >> s;
        cycle = false;
        out.clear();
        if (s.size() == 1){
            cout << "YES\n";
            for (int i = 0; i < 26; i++){
                char c = i + 'a';
                cout << c;
            }
            cout << "\n";
            continue;
        }
        for (int i = 0; i < 26; i++)
            g[i].clear(),vis[i] = 0;
        for (int i = 1; i < sz(s); i++){
            int u = s[i] - 'a';
            int v = s[i-1] - 'a';
            g[u].insert(v);
            g[v].insert(u);
        }
        bool cond  = false;
        int start = -1;
        for (int i = 0; i < 26; i++)
            if (g[i].size() >= 3) cond = true;
            else if(g[i].size() == 1) start = i;
        if (start != -1)
        dfs(start,start);
        if (cond or start == -1){
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        for (auto cur : out){
            char c = cur + 'a';
            cout << c;
        }
        for (int i = 0; i < 26; i++){
            if (!vis[i]){
                char c = i + 'a';
                cout << c;
            }
        }
        cout << endl;


    }
}