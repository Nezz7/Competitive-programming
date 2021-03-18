const LL mod = 1e9 + 7;
LL add(LL x, LL y){
    x += y;
    if(x >= mod) x -= mod;
    return x;
}
LL sub(LL x, LL y){
    x -= y;
    if(x < 0) x += mod;
    return x;
}
LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
LL fast(LL b, LL e){
    if(!e)return 1;
    if(e & 1)return b * 1ll * fast(b, e-1) % mod;
    return fast(b * 1ll * b % mod, e >> 1);
}

 LL inv(LL x){
    return fast(x ,mod - 2);
}

void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}
void mod_inv(int m){
    inv[1] = 1;
    for(int i = 2; i < m; ++i)
        inv[i] = (m - (m/i) * inv[m%i] % m) % m;
}
int is_prime[MAXN],u[MAXN];
int moebus_inversion(){
    /*
    μ(n) = 1 if n is a square-free positive integer with an even number of prime factors.
    μ(n) = −1 if n is a square-free positive integer with an odd number of prime factors.
    μ(n) = 0 if n has a squared prime factor.*/
    is_prime[1] = 1;
    for(int i = 1; i < MAXN; i++)
        u[i] = 1;
    for(int i = 2; i < MAXN; i++){
        if(!is_prime[i]){
            u[i] = -1;
            for(int j = 2 * i; j < MAXN; j += i)
                is_prime[j] = i, u[j] = (j % (i * 1LL * i)) ? - u[j] : 0; 
        }
    }
}
int gcd(int a, int b){
    if(a > b)return gcd(b, a);
    if(a == 0)return b;
    return gcd(b % a, a);
}

int C[100][100]; 
int binomialCoeff(int n, int k) { 
    int i, j; 
    for (i = 0; i <= n; i++) { 
        for (j = 0; j <= min(i, k); j++) { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j]; 
        } 
    } 
} 