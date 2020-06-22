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
    LL u,v;
    cin >> u >> v;
    if ( u == v  && !u){
        cout << 0 ;
        return 0;
    }
    if (u > v or u % 2 != v % 2){
        cout << -1;
        return 0;
    }
    vector<LL> ans;
    LL p = v - u;
    LL x  = 0;
    LL y  = 0;
    for (int i = 60; i >= 0; i--){
        LL bit = (p & (1LL<< i));
        if (bit == 0) continue;
        int j = i - 1;
        x |= (1LL<< j);
        y |= (1LL<< j);
    }
    if ((x | u) == x + u){
        ans.pb(x + u);
        if (y)
        ans.pb(y);
    }else{
    ans.pb(u); 
    if (x) ans.pb(x);
    if (y) ans.pb(y);
    }
    cout << ans.size() << endl;
    for (auto cur : ans) cout << cur << " ";
}