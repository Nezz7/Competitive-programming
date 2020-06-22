#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const mod = 998244353;
int main(){
    ios_base::sync_with_stdio(0);
    cin . tie (0), cout . tie (0);
    int n;
    cin >> n;
    int last = n;
    LL c[n], b[n], a[n];
    for (int  i = 0; i <= (n+1)/2 ; i++){
            c[i] = c[n - 1 - i] = last * (i+1);
            last --;
    }

    for (int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = a[i] * c[i];
    }
    sort (a,a+n);
    for (int i = 0; i < n; i++){
        cin >> b[i];
    }
    sort(b, b+n);
    reverse(b,b+n);
    LL ans  = 0;
    for (int i = 0 ; i < n ; i++){
        ans = (ans % mod + ((a[i]% mod) * (b[i])% mod ) % mod) % mod;
    }
    cout << ans << "\n";

}
