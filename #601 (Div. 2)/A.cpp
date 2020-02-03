#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 3e5+9;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL a,b;
        cin >> a >> b;
        LL x = abs(a-b);
        LL ans = x/5;
        x%=5;
        ans += x/2;
        x%=2;
        ans+=x;
        cout  << ans << "\n";

    }
}
