struct custom_hash {
      static uint64_t splitmix64(uint64_t x) {
            x += 0x9e3779b97f4a7c15;
            x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
            x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
            return x ^ (x >> 31);
      }
      size_t operator()(uint64_t x) const {
            static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
            return splitmix64(x + FIXED_RANDOM);
      }
};
unordered_map<int, int, custom_hash> safe_map;
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