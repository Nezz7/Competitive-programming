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
LL n, h;
LL get(LL x){
    return x * (x + 1)/ 2;
}
LL mini (LL x, LL mx){
    
}
bool check(LL x){
    
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> n >> h;
    LL low = 1, hi = n;
    LL ans = 0;
    while(low <= hi){
        LL mid = (low + hi + 1) / 2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }else low = mid + 1;
    }
    cout << ans << endl;
}