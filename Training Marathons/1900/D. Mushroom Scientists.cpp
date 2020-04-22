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
LD const EPS = 1e-6;
LD get(LD x){
    if (x == 0) return log(0.0000005);
    return log(x);
}

inline bool GT(const LD &a, const LD &b){return fabs(a-b) > EPS && a > b;}

int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    LD S; cin >> S;
    LD a, b, c; cin >> a >> b >> c;
    LD sum = max(1.L, a + b + c);
    cout << fixed << setprecision(14) << S * a / sum << ' ' << S * b / sum << ' ' << S * c / sum << '\n';
}