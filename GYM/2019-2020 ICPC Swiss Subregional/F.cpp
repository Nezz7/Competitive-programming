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
        LL x, y, xx, yy;
        cin >> x >> y >> xx >> yy;
        LL lx1 = min(x, xx);
        LL rx1 = max(x, xx);
        LL ly1 = min(y, yy);
        LL ry1 = max(y, yy);
        cin >> x >> y >> xx >> yy;
        LL lx2 = min(x, xx);
        LL rx2 = max(x, xx);
        LL ly2 = min(y, yy);
        LL ry2 = max(y, yy);
        LL area1 = (rx1 - lx1) * (ry1 - ly1);
        LL area2 = (rx2 - lx2) * (ry2 - ly2);

        LL ans = max(area1, area2);

        if(rx1 < lx2 or rx2 < lx1){
            cout << ans << endl;
        }else {
            if(ry1 < ly2 or ry2 < ly1){
                cout << ans << endl;
            }else {
                LL lenx = max(rx1, rx2) - min(lx1, lx2);
                LL leny = max(ry1, ry2) - min(ly1, ly2);
                LL xx = min(rx1, rx2) - max(lx1, lx2);
                LL yy = min(ry1, ry2) - max(ly1, ly2);
                LL ans2 = max(lenx * yy, leny * xx);
                cout << max(ans2, ans) << endl;
                
            }
        }

    }
}