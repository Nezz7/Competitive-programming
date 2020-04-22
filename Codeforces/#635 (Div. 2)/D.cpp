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
int const MAXN = 2e5 + 9;
int sz[3];
LL a[3][MAXN];
int p[3];
LL up (LL x,int i){
    auto it = lower_bound(a[i],a[i]+sz[i],x) - a[i];
    if (it < sz[i]) return a[i][it];
    return a[i][0];
}
LL down (LL x, int i){
    auto it = lower_bound(a[i],a[i]+sz[i],x + 1) - a[i]- 1;
    if ( it < 0) return a[i][0];
    return a[i][it];
}
LL eq (LL x, LL y, LL z){
    LL a = (x - y);
    LL b = (x - z);
    LL c = (z - y);
    return  (a * a) + (b * b) + (c * c);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> sz[0] >> sz[1] >> sz[2];
        for(int i = 0; i < sz[0]; i++) cin >> a[0][i];
        for(int i = 0; i < sz[1]; i++) cin >> a[1][i];
        for(int i = 0; i < sz[2]; i++) cin >> a[2][i];
        for(int i = 0; i < 3; i++) sort(a[i],a[i] + sz[i]);
        for(int i = 0; i < 3; i++) p[i] = i;
        LL ans = LLONG_MAX;
        do{
           int i = p[0];
           int j = p[1];
           int k = p[2];
           for(int idx = 0; idx < sz[i]; idx++){
                LL x = a[i][idx];
                LL y = up(x,j);
                LL z = down(x,k);
                ans = min(ans,eq(x,y,z));
           }
        }while(next_permutation(p,p+3));
      
        cout << ans << endl;
    }
}