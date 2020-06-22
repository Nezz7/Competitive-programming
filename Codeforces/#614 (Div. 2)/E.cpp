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
LL x0,y0,ax,ay,bx,by;
LL xs, ys,t;
LL curT,startX,startY;
bool check (LL x){
    LL xx = startY;
    LL yy = startX;
    for(int i = 2; i <= x; i++){
        if(xx > inf/ax or  (xx + bx) > inf/ ax) return false;
        xx = ax * xx + bx;
        if(yy > inf/ay or  (yy + by) > inf/ ay) return false;
        yy = ay * yy + by;
    }
    LL dist = abs(startX - xx) + abs(yy - startY);
    return dist <= curT;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    cin >> x0 >> y0 >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    vector<pair<LL,LL>> v;
    LL nbr = 0;
    LL xx = x0;
    LL yy = y0;
    v.emplace_back(x0,y0);
    int cnt = 0;
    for(int i = 2; true ; i++){
        if(xx == xs && yy == ys) cnt = 1;
        if(xx > inf/ax or  (xx + bx) > inf/ ax) break;
        xx = ax * xx + bx;
        if(yy > inf/ay or  (yy + by) > inf/ ay) break;
        yy = ay * yy + by;
        v.emplace_back(xx,yy);
        if(xx > xs && yy > ys) break;
    }
    LL ans = 0;
    for(int i = 0; i < sz(v); i++){
        LL x = v[i].first;
        LL y = v[i].second;
        LL d = abs(xs - x) + abs(y - ys);
        startX = x;
        startY = y;
        curT = t - d;
        if(curT < 0) continue;
        for(int j = 0; j <= i; j++){
            int xx = v[j].first;
            int yy = v[j].second;
            if(xx >= xs && yy >= ys) nbr++;
        }
        if(nbr == 0){
             for(int j = i; j < sz(v); j++){
            int xx = v[j].first;
            int yy = v[j].second;
            if(xx <= xs && yy <= ys) nbr++;
            }
        }
        nbr --;
        LL f = nbr;
        LL low = 1, high = 1e16;
        while(low <= high){
            LL mid = (low + high + 1) / 2; 
            if(check(mid)){
                f = mid + nbr;
                low = mid + 1;
            }else high = mid - 1;
        }
        ans = max(ans,f);
    }
    v.emplace_back(xs,ys);
   
    cout << ans << endl;
}