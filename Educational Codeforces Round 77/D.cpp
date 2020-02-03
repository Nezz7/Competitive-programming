#include <bits/stdc++.h>
#define LL long long int
using namespace std;
int const MAXN = 2e6+9;
int m, n, k, t;
int a[MAXN];
vector<pair<pair<int,int>,int>> v;
bool check (int x){
    int mn = a[x-1];
    int cur = n;
    int l = 0, r = 0;
    for (int i = 0; i < k; i++){
        if (v[i].second < mn ) continue;
        if (v[i].first.second <= r) continue;
        if (v[i].first.first > r){
            cur
        }
    }S

    return
}
int main(){
    ios_base::sync_with_stdio(0);
    cin . tie(0) , cout.tie(0);
    cin >> m >> n >> k >> t;
    for (int i  = 0; i < m; i++)
        cin >> a[i];
        n++;
    sort (a,a+m);
    reverse(a,a+m);
    for (int i = 0; i < k ;i++){
        int l, r, d;
        cin >> l >> r >> d;
        v.push_back({{l,r},d});
    }
    sort(v.begin(),v.end());
    int ans = 0;
    int l  = 1, r = m;
    while (l <= r){
        int mid = (r+l)/2;
        if (check (mid)){
            ans = mid;
            l = mid + 1;
        }else r = mid - 1;

    }
    cout << ans << "\n";

}
