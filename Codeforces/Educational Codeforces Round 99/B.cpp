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
LL a[MAXN];
LL get(LL x){
    return (x + 1) * x / 2;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        LL low = 1, high = 1e6;
        LL ans = 0;
        while(low <= high){
            LL mid = (low + high) / 2;
            if(get(mid) >= n){
                ans = mid;
                high = mid - 1;
            }else low = mid + 1;
        }
        if(get(ans) == n)  cout << ans << endl;
        else if(get(ans) - n >= 2 && get(ans) - n <= ans) cout << ans << endl;
        else cout << ans + 1 << endl;
    }
}