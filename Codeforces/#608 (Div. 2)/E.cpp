#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN  = 2e6 + 9;
vector<LL> ans;
LL p[100];
LL n, k;
LL lvl = 1;
LL get (LL x){
 LL lvl = 1;
    while (x > 1){
        x /=2;
        lvl ++;
    }
    return lvl;
}
LL ok (LL x){
    LL d = lvl - get(x);
    LL ans = p[d];
    LL y = p[d];
    while (d){
        d--;
        x*=2;
    }
    cout << x << " " << n;
    if (n >= x) y++;
    if (n >= x+1) y++;
    return y >= k;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;
    p[0] = 1;
    for (int i = 1; i < 60 ; i++)
        p[i] = p[i-1] * 2;
    LL L = 1, R= n;
    LL ans = 1;
    LL u = n;
    while (u > 1){
        u /=2;
        lvl ++;
    }
    cout << lvl  << endl;;
    ok (5);
    /*    while (L  < R){
        LL mid = (L+R)/2;
        if (ok(mid)){
            ans = mid;
            L = mid +1;
        }else R = mid - 1;
    }*/
    cout << ans;
}
