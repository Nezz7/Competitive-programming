#include <bits/stdc++.h>

using namespace std;
int const MAXN = 2e5;
int p[MAXN],vis[MAXN];
int find_set (int x){
    if (p[x] == x) return x;
    return p[x] = find_set(p[x]);
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int ans[n], a[n];
        bool cond = true;
        for (int i = 0; i <= n;i++) vis[i]=0,p[i]=i,ans[i]=-1;
        for (int i = 0; i < n;i++){
            cin >> a[i];
           if(!vis[a[i]]){
                vis[a[i]] = 1;
                ans[i]= a[i];
                p[a[i]] = a[i] -1;
           }
        }
        for (int i = 1; i < n;i++){
            if (ans[i]==-1){
                ans[i] = find_set(ans[i-1]);
                if (ans[i] == 0) break;
                p[ans[i]] = ans[i] -1;
            }
        }
        for (int i = 0; i < n ; i++) if (ans[i] == 0) cond = false;
        if (cond){
            for(auto cur : ans)
                cout << cur <<" ";
        }else cout << -1;
        cout << "\n";
    }
}
