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
int n, m;
int mul(int a, int b, int m){
    return (a * 1LL * b) % m;
}
int fast(int a, int b,int m){
    if(b == 0) return 1;
    int x = fast(a,b/2,m);
    if(b & 1) return mul(a,mul(x,x,m),m);
    return mul(x,x,m);
}
int f (int n, int m){
    if(n == 1) return 1;
    return fast(n,f(n-1,m),m);
}
int phi(int m){
    int ret = m;
    for(LL i = 2; i * i <= m; i++){
        if(m % i == 0) ret -= ret/i;
        while(m % i == 0){
            m/= i;
        }
    }
    if(m > 1){
        ret -= ret/m;
    }
    return ret;
}
int f2(int n, int m){
    if (m == 1) return 0;
    if (n <= 4) return f(n,m);
    int ph = phi(m);
    int x = f2(n - 1, ph);
    return fast(n,ph + x, m);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> m;
    cout << f2(n,m);
}