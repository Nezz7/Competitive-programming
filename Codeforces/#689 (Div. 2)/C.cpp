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
int const MAXN = 2e6 + 9;
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    cout << setprecision(20);
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        int x = 0;
        for(int i = n; i > 0; i--){
            if(a[i] != i){
                x = i;
                break;
            }
        }
        LD p = 1;
        LD ans = 0;
        debug(x);
        for(int i = 0; i < m; i++){
            int r;
            LD pi;
            cin >> r >> pi;
            if(r >= x){
                ans += pi*p;
                p = (1 - pi)*p;
            }
        }
        if(x == 0){
            cout << 1 << endl;
            continue;
        }else cout << ans << endl;
    }
}