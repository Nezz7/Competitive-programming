LL mul (LL a, LL b){
    return ((a % mod) * (b % mod)) % mod ;
}
LL exp (LL a, LL b){
    if (b == 0) return 1LL;
    LL x = exp(a,b/2);
    if (b%2) return  mul(x,mul(x,a));
    return  mul(x,x);
}