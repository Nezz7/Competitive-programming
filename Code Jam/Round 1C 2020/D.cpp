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
int const MAXN = 1e5 + 9;
LL a[MAXN];
map<LL,int> mp;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    int cc = 0;
    while (T--){
        cc++;
        int n,d;
        cin >> n >> d;
        int mx = 0;
        mp.clear();
        LL b = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[a[i]]++;
            mx = max(mp[a[i]],mx);
            b = max(b,a[i]);
        }
        LL ans = d - 1;
        for(auto cur : mp){
            if(cur.second >= d) {ans = 0; continue;}
            LL x = d - cur.second;
            LL mn = 0;
            vector<LL> v;
            for(int i = 0; i < n; i++){
                if(a[i] > cur.first){
                    if(a[i] % cur.first == 0){
                        LL q = a[i] / cur.first;
                        v.pb(q);
                    }
                }
            }
            sort(all(v));
            for(int i = 0; i < sz(v); i++){
                if(x){
                    if(v[i] <= x){
                        x -= v[i];
                        mn += v[i] - 1;
                    }else {
                        mn += x;
                        x  = 0;
                    }
                }
            }
            if(x == 0) ans = min(ans,mn);
            else {
                for(int i = 0; i < n; i++){
                    if((a[i] > cur.second) && (a[i] % cur.first) && x){
                        LL q = a[i]/ cur.first;
                        if(q <= x){
                            x -= q;
                            mn += q;
                        }else {
                            mn += x;
                            x  = 0;
                        }
                    }
                }
                if(x == 0) ans = min(ans,mn);
            }
        }
        
        cout << "Case #"  << cc << ": " << ans << endl;
    }
}