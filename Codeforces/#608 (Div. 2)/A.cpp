#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN  = 2e6 + 9;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    LL a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    LL x = min(a,d);
    LL ans = min(a,d) * e + min({b,c,max(d-x,0LL)})*f;
    LL ans2 = min({b,c,d})*f + min(a,max(d-min({b,c,d}),0LL))*e;
    cout << max(ans2,ans);

}
