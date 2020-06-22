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
int n;
bool check (LL x){
    LL cur = n - 1 - x;
    LL have = 1;
    for(LL day = 0; day < x; day++){
        LL po = cur /(x - day);
        LL mn = min(po,have);
        have = 2 * (mn) + (have - mn);
        cur -=  (x - day) * mn;
        if(cur == 0) return true;
    }
    return false;
}
void out (LL x){
    LL cur = n - 1 - x;
    LL have = 1;
    for(LL day = 0; day < x; day++){
        LL po = cur /(x - day);
        LL mn = min(po,have);
        have = 2 * (mn) + (have - mn);
        cur -=  (x - day) * (mn);
        cout << mn << ' ';
    }
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        int low = 0, hi = 1e4;
        int ans  = 0;
        while(low <= hi){
            int mid = (low + hi + 1)/2;
            if(check(mid)){
                ans = mid;
                hi = mid - 1;
            }else low = mid + 1;
        }
        cout << ans << endl;
        out(ans);
        cout << endl;
    }
}