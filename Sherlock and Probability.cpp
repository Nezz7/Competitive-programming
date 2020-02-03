#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int  main (){
    LL T;
    cin >> T;
    while (T--){
        LL n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        LL sum[n+1];
        memset(sum,0,sizeof sum);
        LL ans = 0;
        for (LL i  = 0; i < n;i++)
            sum[i + 1] = (s[i]=='1') + sum[i];
        for (LL i = 0; i < n; i++){
            if (s[i] == '1'){
                LL last = max(i - k,0LL);
                LL nxt = min (i + 1 + k,n);
                ans += sum[nxt]-sum[last];
            }
        }
        LL b = n*n;
        LL g = __gcd(b,ans);
        ans /= g;
        b /= g;
        if (ans == 0){
            cout << 0 << "/" << 1 << endl;
        }else
        cout << ans << "/" << b << endl;
    }

}
