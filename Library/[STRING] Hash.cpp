struct Hash{
    vector<LL> h;
    const int p = 31;
    const int m = 1e9+9;
    vector<LL> p_pow;
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
    Hash(string &s){
        int n = s.size();
        p_pow.resize(n + 2);
        h.resize(n + 2);
        LL cur = 0;
        for(int i = 0; i < n; i++){
            cur = add((s[i] - 'a' + 1),mul(cur,p));
            h[i] = cur;
        }
        p_pow[0] = 1;
        for (int i = 1; i <= n; i++)
            p_pow[i] = (p_pow[i - 1] * p) % m;

    }
    int get(int l, int r){
        int b = h[r];
        int a = (l == 0) ? 0 : mul(h[l - 1],p_pow[r - l + 1]);
        return sub(b,a);
    }
};