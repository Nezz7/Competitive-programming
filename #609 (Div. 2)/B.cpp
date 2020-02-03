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
 int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n, m;
    cin >> n >> m;
    LL a[n], b[n];
    unordered_map<LL,int> mp , o;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        mp[a[i]]++;
    }
     for (int i = 0; i < n; i++){
        cin >> b[i];
        o[b[i]]++;
    }
    LL ans = 1e9;
    for (int i = 0; i < n; i++){
       LL x = (b[0] - a[i] + m) % m;
       if (x > ans) continue;
       bool cond = true;
       for (auto cur : mp){
            if (o[(cur.first + x)%m] != cur.second) cond = false;
            if (cond == false) break;
       }
       if (cond) ans = min(ans, x);
    }
    cout << ans << endl;
 }
