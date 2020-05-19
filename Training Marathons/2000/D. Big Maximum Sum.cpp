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
vector <vector<int>> g;
int a[MAXN];
LL l[100],r[100],sum[100],mx[100];
LL pref[MAXN];
void get(int idx){
    LL cur  = 0;
    pref[0] = 0;
    for(int i = 0; i < sz(g[idx]); i++){
        sum[idx] += g[idx][i]; 
        pref[i + 1] = pref[i] + g[idx][i];
        l[idx] = max(pref[i + 1],l[idx]);
        cur = max(cur,0LL);   
        cur += g[idx][i];
        mx[idx] = max(mx[idx],cur);
    }
    r[idx] = sum[idx];
    for(int i = 0; i < sz(g[idx]) - 1; i++){
        r[idx] = max(r[idx], sum[idx] - pref[i + 1]);
    } 
  
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for(int i = 0; i < 100 ; i++){
        mx[i] = l[i] = r[i] = -1e9;
    }
    int n,m;
    cin >> n >> m;
    g.resize(n + 1);
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        for(int j = 0; j < x; j++){
            int a;
            cin >> a;
            g[i].pb(a);
        }
        get(i);
    }
    for(int i = 0; i < m; i++){
        cin >> a[i];
        a[i]--;
    }
    LL ans = -1e9;
    LL all = 0;
    for(int i = 0; i < m; i++){
        int idx = a[i];
        if(all <= 0) all = 0;
        ans = max(ans,mx[idx]);
        ans = max(ans,all + l[idx]);
        all += sum[idx];
        all = max(r[idx],all);
        ans = max(ans,all);
    }
    cout << ans << endl;
}