const LL mod = 1e9 + 7;
int gcd (int a, int b){
    if (!b) return a;
    return gcd(b, a % b);
}
inline LL add(LL x, LL y){
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
inline LL sub(LL x, LL y){
    x -= y;
    if(x < 0) x += mod;
    return x;
}
inline LL mult(LL x, LL y){
    return x * 1ll * y % mod;
}
LL fast(LL b, LL e){
    if(!e)return 1;
    if(e&1)return b * 1ll * fast(b,e-1) % mod;
    return fast(b * 1ll * b % mod, e >> 1);
}

inline LL inv(LL x){
    return fast(x,mod-2);
}