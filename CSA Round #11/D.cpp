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
 int const inf = 1e9;
 int no[MAXN],d[MAXN];
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, k , m , s;
    cin >> n >> k >> m >> s;
    for (int i = 0; i < m; i++){
         int x;
         cin >> x;
         no[x] = 1;
    }
    for (int i = 0; i < n; i++)
        d[i+1] = inf;
    queue<int> q;
    q.push(s);
    d[s] = 0;
    while (!q.empty()){
        int u = q.front();
        cout << "visiting " << u << endl;
        q.pop();
        if (no[u]) continue;
        for (int i = 1; i <= k; i++){
            if (u < i) break;
            int x = k + 1 - i;
            debug(x);
            int dist = x - i;
            debug(u+dist)
            if (u + dist <= n && !no[u+dist] && d[u+dist] > d[u] + 1){
                d[u+dist] = d[u] + 1;
                q.push(u+dist);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if (d[i] == inf) cout << -1 <<" ";
        else cout << d[i] << " ";
    }
 }
