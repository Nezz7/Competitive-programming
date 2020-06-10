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
map<int,int> occ;
map<int,int> cost;
set<int> st;
const LL mod = 1e9 + 7;
LL add(LL x, LL y){
    x %= mod;
    return (x + y) % mod;
}
LL sub(LL x, LL y){
    return ((x - y) % mod + mod) % mod;
}
LL mul(LL x, LL y){
    x %= mod;
    return (x * 1ll * y)% mod;
}
LL fast(LL b, LL e){
    if(!e)return 1;
    if(e & 1)return b * 1ll * fast(b, e-1) % mod;
    return fast(b * 1ll * b % mod, e >> 1);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        LL n, p;
        cin >> n >> p;
        occ.clear();
        st.clear();
        for(int i = 0; i < n; i++){
            int x;
            cin >> x;
            occ[x]++;
        } 
        if(p == 1){
            cout << (n & 1) << endl;
            continue;
        }
        vector<pair<int,int>> v;
        for(auto cur : occ){
            int a = cur.first;
            int b = cur.second;
            occ[a] = b % p;
            if(b / p >= 1){
                occ[a + 1] += b / p;
                st.insert(a + 1);
            }
            if(b % p)
                v.emplace_back(a,b % p);
        }
        reverse(all(v));
        bool cond = false;
        LL ans1 = 0;
        LL ans2 = 0;
        for(auto cur : v){
            LL x = cur.first;
            LL b = occ[x];
            cout << x << " " << b << endl;
            if(cond){
                ans2 = add(ans2,mul(b,fast(p,x)));
                continue;
            }
            if((b & 1)){
                if(p & 1){
                    if(st.count(x)){
                        if(!occ[x - 1]){
                            cond = true;
                            ans1 = fast(p,x - 1);
                        }else occ[x - 1]++;
                    }else {
                        cond = true;
                        ans1 = fast(p,x);
                    }
                }else {
                    if(!st.count(x)){
                        cond = true;
                        ans1 = fast(p,x);
                    }
                }
            }
        }
        cout << sub(ans1, ans2) << endl;
    }
}