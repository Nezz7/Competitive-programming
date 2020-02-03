#include  <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e5+9;
LL a[MAXN];
int ans[MAXN];
int n;
vector<vector<int>>adj;
int main (){
    memset(ans,-1,sizeof ans);
    cin >> n;
    adj.resize(n+1);
    queue<int> q;
    for (int i  = 0; i < n; i++) cin >> a[i];
    for (int i  = 0; i < n; i++){
        int u = i - a[i];
        if (u >= 0) adj[u].push_back (i);
        if (u >= 0 && a[i] % 2 != a[u] % 2){
            q.push(i);
            ans[i] = 1;
         }
        u = i + a[i];
        if (u < n) adj[u].push_back (i);
        if (u < n && a[i] % 2 != a[u] % 2){
                if (ans[i]== -1){
                    q.push(i);
                    ans[i] = 1;
                }
        }
    }
    while (!q.empty()){
        int u = q.front();
        q . pop();
        for (auto child : adj[u]){
            if (ans[child] == -1){
                ans[child] = 1 + ans[u];
                q.push(child);
            }
        }
    }
    for (int i  = 0; i < n; i++)
        cout << ans[i] << " ";
}
