#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        int a[n];
        int L=0,R=0;
        for (int i = 0; i < n;i++){
            cin >> a[i];
            if (a[i]  == 1) L = i,R =i;
        }
        int mn = n+5,mx = 0;
        int ans[n];
        ans [0] = 1;
        for (int i = 0; i < n-1;i++){
            if (L > 0 && R < n - 1){
                if (a[R+1] < a[L-1]){
                    R++;
                }else L--;
            }else if (L > 0) L --;
            else R++;
            mn = min({mn,a[L],a[R]});
            mx = max({mx,a[L],a[R]});
            ans [R-L]=((R-L+1) == (mx-mn+1));

        }
        for (auto cur : ans) cout << cur;
        cout << "\n";

    }
}
