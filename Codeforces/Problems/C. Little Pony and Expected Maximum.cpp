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
LD fast(LD b, LL e){
    if(!e)return 1.L;
    if(e&1)return b * fast(b,e-1) ;
    return fast(b * b, e >> 1);
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n,m;
    cin >> m >> n;
    LD ans = 0;
    for (int i = 1; i <= m; i++){
        ans+= (fast(i/(long double) m ,n) - fast((i-1)/(long double) m,n)) * i;
    }
    cout << setprecision(26) << ans;
    }