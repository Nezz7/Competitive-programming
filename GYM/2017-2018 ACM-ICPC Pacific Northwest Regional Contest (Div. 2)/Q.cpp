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
    LL n;
    cin >> n;
    LL s = (n) * (n - 1) / 2;
    LL x = (s + 1) / 2;
    LL l = 1, r = n;
    LL ans = 9;
    while (l <= r ){
        LL mid = (l + r)/2;
        LL e = n - 1;
        LL s = n - mid;
        LL g = (e + s) * (e - s + 1) / 2;
        if (g >= x){
            ans = mid;
            r = mid - 1;
        }else l = mid + 1;
    }
    cout << ans << endl;
}