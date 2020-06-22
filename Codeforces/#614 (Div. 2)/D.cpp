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
LL inf = 1e18;
LL pax[MAXN];
LL pay[MAXN];
LL x0,y0,ax,ay,bx,by;
LL xs, ys,t;
bool check (LL x){
    if (x > 60 && ax != 1 && ay != 1) return false;
    if(pax[x] == -1 or pay[x] == -1) return false;
    LL xx = x0;
    LL yy = y0;
    for(int i = 2; i <= x; i++){
        if(xx > inf/ax or  (xx + bx) > inf/ ax) return false;
        xx = ax * xx + bx;
        if(yy > inf/ay or  (yy + by) > inf/ ay) return false;
        yy = ay * yy + by;
    }
    LL dist = abs(xs - xx) + abs(yy - ys);
    return dist <= t;
}
bool check2 (LL x){
    if (x > 60 && ax != 1 && ay != 1) return false;
    if(pax[x] == -1 or pay[x] == -1) return false;
    LL xx = x0;
    LL yy = y0;
    for(int i = 2; i <= x; i++){
        if(xx > inf/ax or  (xx + bx) > inf/ ax) return false;
        xx = ax * xx + bx;
        if(yy > inf/ay or  (yy + by) > inf/ ay) return false;
        yy = ay * yy + by;
    }
    LL dist = abs(x0 - xx) + abs(y0 - yy) + abs(x0 - xs) + abs(ys - y0);
    return dist <= t;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    if (ax == 1 && ay == 1 && by == 0 && bx == 0){
        //simple case
        LL dist = abs(x0 - xs) + abs(ys - y0);
        cout << (dist <= t) << endl;
        return 0;
    }
    pax[0] = 1;
    for(int i = 1; i < 60; i++){
        if(pax[i - 1] == -1) pax[i] = -1;
        else {
            if(ax > inf / pax[i - 1]) pax[i] = -1;
            else pax[i] = ax * pax[i - 1];
        }
    }
    pay[0] = 1;
    for(int i = 1; i < 60; i++){
        if(pay[i - 1] == -1) pay[i] = -1;
        else {
            if(ay > inf / pay[i - 1]) pay[i] = -1;
            else pay[i] = ay * pay[i - 1];
        }
    }
    vector<pair<LL,LL>> v;
    LL nbr = 0;
    LL xx = x0;
    LL yy = y0;
    v.emplace_back(x0,y0);
    for(int i = 2; true ; i++){
        if(xx > inf/ax or  (xx + bx) > inf/ ax) break;
        xx = ax * xx + bx;
        if(yy > inf/ay or  (yy + by) > inf/ ay) break;
        yy = ay * yy + by;
        v.emplace_back(xx,yy);
    }
    auto it = lower_bound(all(v),make_pair(xs,ys)) - v.begin(); 
    if(x0 == xs && y0 == ys) nbr = 0;
    else nbr = it;
    //from start to x
    LL f = 0;
    LL low = 1, high = 1e16;
    while(low <= high){
        LL mid = (low + high + 1) / 2; 
        if(check(mid)){
            f = mid;
            low = mid + 1;
        }else high = mid - 1;
    }
    f -= nbr;
    // from start to s0 then to x;
    LL s = 0;
    low = 1, high = 1e16;
    while(low <= high){
        LL mid = (low + high + 1) / 2; 
        if(check2(mid)){
            s = mid;
            low = mid + 1;
        }else high = mid - 1;
    }
    cout << max(s,f) << endl;
}