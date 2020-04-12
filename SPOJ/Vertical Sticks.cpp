#include <bits/stdc++.h>
#define endl '\n'
#define LL long long
#define LD long double
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 100 + 9;
int a[MAXN];
LL c[MAXN][MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    for(int i = 0; i < MAXN; i++){
        for(int j = 0; j <= min(i,MAXN); j++){
            if ( j == 0 or j == i) c[i][j] = 1;
            else c[i][j] = c[i-1][j-1] + c[i - 1][j];
        }
    }
    int T;
    cin >> T;
    while (T--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        double ans = 0;
        for (int i = 1; i <= n; i++){
            LL r = 0;
            for(int j = 1; j <= n; j++){
                if (a[j] < a[i]) r++;
            }
            for (LL p = 1; p <= n; p++){
                for(LL k = 0; k <= min(p-1,r); k++){
                    if (k == p - 1){
                        ans += (k + 1) * c[r][k] / (double)( n * c[n - 1][k]);
                    }else ans += (k + 1) * c[r][k] * (n - r - 1) / (double)( n * (n - 1) * c[n-2][k] );
                }
            }
        }
        cout << fixed;
        cout << setprecision(2);
        cout << ans << endl;
    }
}