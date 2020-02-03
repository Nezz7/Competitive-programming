 #include <bits/stdc++.h>
 #define f first
 #define s second
 #define endl '\n'
 #define LL long long int
 #define pb push_back
 #define sz(a) (LL)a.size()
 #define all(a) a.begin(),a.end()
 #define rall(a) a.rbegin(),a.rend()
 #define debug(x) cerr << #x << " is " << x << endl;

using namespace std;

 LL const MAXN = 2e6 + 9;
 bool cond (vector<LL> v){
    LL mn  = v[0];
    for (auto cur : v){
        mn = min(cur,mn);
        if (mn < cur) return true;
    }
    return false;
 }
 int  main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n;
    cin >> n;
    vector<vector<LL>> adj(n+1);
    vector<LL> maxi;
    for (LL i  = 0; i < n; i++){
        LL l;
        cin >> l;
        LL mx = 0;
        for (LL j = 0; j < l; j++){
            LL x;
            cin >> x;
            mx=max(mx,x);
            adj[i].push_back(x);
        }
    }
    LL ans = 0;
    LL y = n;
    vector<LL> del;
    for (LL i = 0; i < n; i++){
        if (cond(adj[i])){
                ans+= 2*y-1,y--;
        }else{
             LL mx = *max_element(all(adj[i]));
            maxi.pb(mx);
        }
    }
    sort(all(maxi));
    for (LL i = 0; i < n; i++){
        if (!cond(adj[i])){
            LL mn = *min_element(all(adj[i]));
            LL cur = upper_bound(all(maxi),mn) - maxi.begin();
            cur = sz(maxi) - cur ;
            ans+= cur;
        }
    }
    cout << ans;
 }
