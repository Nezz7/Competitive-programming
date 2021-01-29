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
LL n, k;
bool check(LL x){
    LL sum = a[0] + x;
    for(int i = 1; i < n; i++){
        if(a[i] * 100L > sum * k){
            return false;
        }
        sum += a[i];
    }
    return true;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i  = 0; i < n; i++){
            cin >> a[i];
        }
        LL low = 0, hi = 1e15;
        LL ans = 0;
        while(low <= hi){
            LL mid = (low + hi) / 2;
            if(check(mid)){
                ans = mid;
                hi = mid - 1;
            }else low = mid + 1;
        }
        cout << ans << endl;
    }
}