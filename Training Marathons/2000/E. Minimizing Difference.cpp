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
map<int,LL> mp;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LL n, k; 
    cin >> n >> k;
    LL low = 1e9, hi = 0;
    vector<int> v;
    for(int i = 0; i < n; i++){
        LL x;
        cin >> x;
        mp[x]++;
        low = min(low, x);
        hi = max(hi, x);
        v.pb(x);
    }
    sort(all(v));
    while(low < hi && k){
        int nxt = *upper_bound(all(v),low);
        int it = lower_bound(all(v),hi) - v.begin() - 1;
        LL prev = v[it];
        LL to_nxt = mp[low] * (nxt - low);
        LL to_prev = mp[hi] * (hi - prev);
        if (mp[low] == mp[hi]){
            if((nxt - low) >= (hi - prev) ){
                if (k >= to_nxt){
                    mp[nxt] += mp[low];
                    low = nxt;
                    k -= to_nxt;
                }else {
                    low = low + k / mp[low];
                    k = 0;
                }
            }else {
                 if (k >= to_prev){
                    mp[prev] += mp[hi];
                    hi = prev;
                    k -= to_prev;
                }else {
                    hi = hi - k / mp[hi];
                    k = 0;
                }
            }
        }else if (mp[low] < mp [hi]) {
             if (k >= to_nxt){
                    mp[nxt] += mp[low];
                    low = nxt;
                    k -= to_nxt;
                }else {
                    low = low + k / mp[low];
                    k = 0;
                }
             }else {
                    if (k >= to_prev){
                    mp[prev] += mp[hi];
                    hi = prev;
                    k -= to_prev;
                }else {
                    hi = hi - k / mp[hi];
                    k = 0;
                }
             }
    }
    cout << hi - low << endl;
}