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
LL a[MAXN];
LL fast(LL b, LL e){
    if(!e)return 1;
    if(e&1)return b * 1ll * fast(b,e-1);
    return fast(b * 1ll * b , e >> 1);
}
int p[MAXN];
map<int,vector<int>> mp;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for(int i = 2; i < MAXN; i++){
        if(!p[i])
        for(int j = i; j < MAXN; j+= i){
            p[j]  = i;
        }
    }
    int n;
    cin >> n;
    LL ans = 1;
    for(int i = 0; i < n; i++){
        cin >> a[i]; 
        while(a[i] > 1){
            int d = p[a[i]];
            int cnt = 0;
            while(a[i] % d == 0 && a[i] > 1){
                cnt ++;
                a[i] /= d;
            }
            mp[d].pb(cnt);
        }
    }
    for(auto cur : mp){
        sort(all(cur.second));
        if(sz(cur.second) == n) ans *= fast(cur.first,cur.second[1]);
        if(sz(cur.second) == n - 1) ans *= fast(cur.first,cur.second[0]);
    }
    cout << ans << endl;
   
}