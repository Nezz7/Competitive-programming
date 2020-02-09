#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;

int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T;;
    cin >> T;
    while (T--){
        int a[3];
        int ans = 0;
        for (int i =0; i < 3;i++)
            cin >> a[i], ans+=a[i];
        sort(a,a+3);
        ans /=2;
        if (a[0] + a[1] < ans)
            ans += a[0] + a[1];
        cout << ans << endl;

    }
}
