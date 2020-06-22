#include <bits/stdc++.h>
#define f first
#define s second
#define endl '\n'
#define LL long long
#define pb push_back
#define sz(a) (int)a.size()
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define debug(x) cerr << #x << " is " << x << endl;
using namespace std;
int const MAXN = 2e6 + 9;
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        LL n, x;
        cin >> n >> x;
        LL a[n];
        LL mx = 0;
        bool cond = false;
        for (int i = 0; i < n; i++){
            cin >> a[i];
            if (a[i] == x) cond = true;
            mx = max(mx,a[i]);
        }
        if (cond == true){
            cout << 1 << endl;
            continue;
        }
        LL ans = 0;
        LL l = 0, r = 1e9;
        while (l <= r){
            LL mid = l + (r - l) / 2; 
            if (mx + mx > x - mid * mx){
                ans = mid;
                r = mid - 1;
            }else l = mid + 1 ;
        }
        for (int i = 0; i < n; i++){
            if (x - ans * mx == a[i]){
                cond = true;
            }
        }
        if (cond == true){
            cout <<  ans + 1 << endl;
            continue;
        }
        cout << ans + 2 << endl;
    }
}