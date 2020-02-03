#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
vector<set<int>> adj;
int vis[27];
void DFS (int node){
    vis[node] = 1;
    for (auto child  : adj[node])
        if (!vis[child]) DFS(child);
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string a[n];
    adj.resize(27);
    set<int> st;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        for (auto c : a[i]){
            st.insert(c-'a');
            for (auto x : a[i]){
                adj[c-'a'].insert(x-'a');
                adj[x-'a'].insert(c-'a');
            }
        }
    }
    int ans = 0;
    for (auto i : st)
        if (!vis[i]) DFS(i),ans++;
    cout << ans<< "\n";
}
