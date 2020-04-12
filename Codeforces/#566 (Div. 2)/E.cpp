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
typedef vector<vector<LL>> matrix;
int const oo = 1e9;
int const mod = 1e9+7;
matrix operator * (matrix &a, matrix &b){
    int n = (int) a.size();
    int m = (int) b.size();
    int p = (int) b[0].size();
    matrix c;
    c.resize(n);
    for (int i = 0; i < n; i++){
        c[i].assign(p,0);
        for (int j = 0; j < p; j++){
            for (int k = 0; k < m; k++){
                 c[i][j] += ((a[i][k] * b[k][j]) % mod);
                 c[i][j] %= mod;
            }
        }
    }
    return c;
}
matrix id (int n){
    matrix a;
    a.resize(n);
    for (int i = 0; i < n; i++){
        a[i].assign(n,0);
        a[i][i]  = 1;
    }
    return a;
}
matrix matrixExp(matrix a , LL n){
    if (n == 0) return id (a.size());
    matrix c = matrixExp(a,n/2);
    c =  c * c;
    if (n % 2) c = c * a;
    return c;
}
inline LL mul(LL x, LL y){
    return x * 1ll * y % mod;
}
LL fast(LL b, LL e){
    if(!e)return 1;
    if(e&1)return b * 1ll * fast(b,e-1) % mod;
    return fast(b * 1ll * b % mod, e >> 1);
}
int main (){
    LL  n,f1,f2,f3,c;
    cin >> n >> f1 >> f2 >> f3 >> c;
    matrix a = id (3);
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (i == 0) a[i][j] = 1;
            else if (i == 1 && j == 0) a[i][j] = 1;
            else if (i == 2 && j == 1) a[i][j] = 1;
            else a[i][j] = 0;
            cout << a[i][j];
        }
    cout << endl;
    }
        cout << endl;

    matrix v;
    v.resize(3);
    a = matrixExp(a, n - 3);
    LL p1 = a[0][2];
    LL p2 = a[0][1];
    LL p3 = a[0][0];
    LL ans  = 1;
    ans = mul(ans,fast(f1,p1));
    ans = mul(ans,fast(f2,p2));
    ans = mul(ans,fast(f3,p3));
    cout << p1 << ' ' << p2 << ' ' << p3 << endl;
    LL sz = (n - 4 + 1);
    LL pc = ( 2 + sz * 2) * sz / 2;
    ans = mul(ans,fast(c,pc));
    cout << ans << endl;
}
