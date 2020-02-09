#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN  = 2e6 + 9;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool valid (int x, int y){
    return x >=0 && y <= 1e9;
}
int main (){
    ios_base::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int n, xs, ys;
    cin >> n >> xs >> ys;
    int x[n],y[n];
    for (int i = 0; i < n;i++){
        cin >> x[i] >> y[i];
    }
    sort(x,x+n);
    sort(y,y+n);
    vector<pair<int,pair<int,int>>> ans;
    for (int i = 0; i < 4; i++){
        int xx = xs + dx[i];
        int yy = ys + dy[i];
        if (valid(xx,yy)){
            int mx = 0;
            if (i == 0){
                mx = upper_bound(y,y+n,ys) - y;
                mx = n - mx;
            }else if (i == 1){
                mx = lower_bound(y,y+n,ys-1) - y;
            }else if (i == 2){
                mx = mx = upper_bound(x,x+n,xs) - x;
                mx = n - mx;
            }else {
                mx = lower_bound(x,x+n,xs-1) - x;

            }
            ans.push_back({mx,{xx,yy}});
        }
    }

    sort(ans.begin(),ans.end());
    reverse(ans.begin(),ans.end());
    cout << ans[0].first << "\n" << ans[0].second.first << " " <<ans[0].second.second;
}
