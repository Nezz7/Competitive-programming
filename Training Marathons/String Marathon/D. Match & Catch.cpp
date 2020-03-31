#include <bits/stdc++.h>
#define f first
#define s second
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
struct Hash{
    vector<LL> h;
    const int p = 31;
    const int m = 1e9+9;
    vector<LL> p_pow;
    vector<LL> p_inv;
    inline LL add(LL x, LL y){
        x += y;
        if(x >= m) x -= m;
        return x;
    }
    inline LL sub(LL x, LL y){
        x -= y;
        if(x < 0) x += m;
        return x;
    }
    inline LL mul(LL x, LL y){
        return x * 1ll * y % m;
    }
    LL fast(LL b, LL e){
        if(!e)return 1;
        if(e&1)return b * 1ll * fast(b,e-1) % m;
        return fast(b * 1ll * b % m, e >> 1);
    }

    inline LL inv(LL x){
        return fast(x,m-2);
    }
    Hash(string &s){
        int n = s.size();
        p_pow.resize(n+1);
        p_inv.resize(m+1);
        h.resize(n+1);
        p_pow[0] = 1;
        for (int i = 1; i < n; i++)
            p_pow[i] = (p_pow[i-1] * p) % m;
        for (int i = 0; i < m; i++){
            p_inv[i] = inv(i);
        }
        LL cur = 0;
        for(int i = 0; i < n; i++){
            cur = add(cur,mul((s[i] - 'a' + 1),p_pow[i]));
            h[i] = cur;
        }
    }
    int rangeHash(int l, int r){
        int b = h[r];
        int a = (l == 0) ? 0 : h[l-1];
        return mul(sub(b,a),p_inv[p_pow[l]]);
    }
};
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    string a,b;
    cin >> a >> b;
    Hash ha(a);
    Hash hb(b);
    unordered_map<LL,int> occA;
    unordered_map<LL,int> occB;
    for(int i = 0; i < a.size(); i++){
        for(int j = i; j < a.size(); j++){
            occA[ha.rangeHash(i,j)]++;
        }
    }
    for(int i = 0; i < b.size(); i++){
        for(int j = i; j < b.size(); j++){
            occB[hb.rangeHash(i,j)]++;
        }
    }
    int ans = 1e9;
    for(int i = 0; i < b.size(); i++){
        for(int j = i; j < b.size(); j++){
            int cur = hb.rangeHash(i,j);
            int len = j - i + 1;
            if(occA[cur] == 1 && occB[cur] == 1){
                ans = min(ans,len);
            }
        }
    }
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
    
    

}