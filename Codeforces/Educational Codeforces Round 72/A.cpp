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
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        LL a,b,x;
        cin >> a >> b >> x;
        int low = a, hi = a + x;
        int ans = -1;
        while(low <= hi){
            int mid = (low + hi) / 2;
            int last = x - (mid - a) + b;
            if(mid > last){
                ans = mid;
                hi = mid - 1;
            }else low = mid + 1;
        }
        if(ans == -1) ans = 0;
        else ans = a + x  - ans + 1;
        cout << ans  << endl;
    }
}