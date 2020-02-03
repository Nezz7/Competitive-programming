#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int main (){
    LL n;
    cin >> n;
    LL ans = 0;
    for (LL i = 2; i*i <= n; i++){
        if (n % i == 0){
            ans = __gcd(i,ans);
            if(n/i != 1)
            ans =__gcd(ans,n/i);
        }
    }
    if (ans)
    cout << ans;
    else cout << n;
}
