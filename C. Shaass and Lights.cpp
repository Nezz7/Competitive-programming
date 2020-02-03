#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const mod = 1e9+7;
LL mul (LL a, LL b){
    return (a * b)% mod;
}
LL get(LL a, LL b){
    if (b < 0 ) return 0;
    if (b == 0) return 1;
    LL  x = get (a,b/2);
    if (b&1) return mul(mul(x,x),a);
    return mul(x,x);
}
int main (){
    int n, m;
    cin >> n >> m;
    LL ans = 0;
    int last = 0;
    for (int i = 0 ; i < m ;i++){
        int x;
        cin >> x;
        if (x != last +1)
            ans = (ans + get(2,x-last-2)) % mod;

         last = x;
    }

    cout << max(ans,1LL) <<"\n";

}
