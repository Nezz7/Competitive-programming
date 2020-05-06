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
        set<LL> st;
        for(int i = 0; i < n; i++){
            LL x = a[i];
            for(LL j = 1; j * j <= x; j++){
                if(x % j == 0){
                    st.insert(j);
                    st.insert(x/j);
                }
            }
        }
        int i = 0;
        for(auto cur : st){
            if(i == 1e6) break;
            i++;
            int y = mp[cur];
            if(y >= d) {ans = 0; continue;}
            LL x = d - y;
            LL mn = 0;
            vector<LL> v;
            for(int i = 0; i < n; i++){
                if(a[i] > cur){
                    if(a[i] % cur == 0){
                        LL q = a[i] / cur;
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
                    if((a[i] > cur) && (a[i] % cur) && x){
                        LL q = a[i]/ cur;
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