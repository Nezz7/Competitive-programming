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
 int const MAXN = 3e5 + 9;
 int g[10][MAXN];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
             cin >> g[i][j];
        }
    }
    int mx = 1 << m;
    int mn = 1e9;
    int ans1 = 0;
    int ans2 = 0;
    for (int msk = 3; msk < mx; msk++){
        if (__builtin_popcount(msk) == 2){
            int a , b;
            a = b = -1;
            for (int i = 0; i <= m ; i++){
                if (msk & (1 << i)){
                    if (a != -1) b= i;
                     else a = i;
                }
            }
            int cur = 1e9;
            for (int i = 0; i < m ;i++){
                cur = min(cur,max(g[a][i],g[b][i]));
            }
            if (cur <= mn){
                mn = cur;
                ans1 = a;
                ans2 = b;
            }
        }
    }
    for (int i  = 0; i < m; i++){
        int cur = *min_element(g[i],g[i]+m);
            if (cur <= mn){
                mn = cur;
                ans1 = i;
                ans2 = i;
            }
    }
    cout << ans1 + 1<< " " << ans2+1 << endl;
 }
