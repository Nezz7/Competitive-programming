#include <bits/stdc++.h>
#define LL long long int
#define sz(x) (int) x.size()
using namespace std;
int const MAXN = 1e5 + 9;
int const MOD = 1e9 + 7;
LL a[71],msk[71];
vector <int> primes;
LL pr[71],p[MAXN];
int n;
LL dp[2][(1 << 20)];
void init (){
   for (int i = 2; i < 71; i++)
        if (!pr[i]){
            for (int j = i; j < 71 ; j+=i)
                   pr[j] =  i ;
            primes.push_back(i);
        }
    for (int i = 2; i <= 70; i++){
        int x = i;
        for (int j  = 0; j < sz(primes); j++){
            int cur = 0;
            while (x % primes[j] == 0){
                x/= primes[j];
                cur++;
            }
            if (cur % 2) msk[i] |= (1<<j);
        }
    }
}
LL get (int x, int k){
    if(a[x] == 0 && k == 0) return p[a[x]];
    return p[a[x] - 1];
}
int main (){
    LL x = 1;
    init();
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> x;
        a[x]++;
    }
    p[0] = 1;
    for (int i = 1; i < MAXN; i++){
        p[i] = (2 * p[i-1]) % MOD;
    }
    dp[0][0] = 1;
    for (int i = 0; i < 71; i++){
        int cur = (i) % 2;
        int nxt = (i + 1) % 2;
        for (int j = 0; j < (1 << 20) ; j++){
            dp[nxt][j] += (dp[cur][j] * get(i,0)) % MOD;
            dp[nxt][j] %= MOD;
            dp[nxt][j ^ msk[i]] += (dp[cur][j] * get(i,1)) % MOD;
            dp[nxt][j ^ msk[i]] %= MOD;
        }
        for (int j = 0; j < (1 << 20); j++) dp[cur][j] = 0;
    }
    cout << (dp[1][0] - 1 + MOD) % MOD;
}
