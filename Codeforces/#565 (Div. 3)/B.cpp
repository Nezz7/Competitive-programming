#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin . tie (0) ; cout . tie (0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int a [4];
        for (int i = 0; i < 4;i++)
            a[i] = 0;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            x%=3;
            a[x]++;
        }
        int ans = a[0] + min(a[1],a[2]);
        int x =min (a[1],a[2]);
        a[1] -= x;
        a[2] -= x;
        ans += a[1]/3;
        ans += a[2]/3;
        cout << ans << "\n";
    }
}
