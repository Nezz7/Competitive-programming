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
int const MAXN = 2e5 + 9;
pair<int,int> inv[MAXN];
LL n, s;
bool check (int x){
    LL cur = 0;
    int gr = 0;
    int i = 0;
    if(n/2)
    for (i = n - 1; i >= 0; i--){
        if(gr == n/2) break;
        if(inv[i].second >= x) gr ++;
    }
    if(gr < n/2) return false;
    for(; i >= 0; i--){
        if(gr > n/2) break;
        if(inv[i].first <= x && x <= inv[i].second) gr++;
    }
    if(gr == n/2) return false;
    cur += x;
    int cnt = 0;
    int start = i;
    for(; i >= 0; i--){
        cur +=inv[i].first;
        cnt++;
    }
    for(int i = n - 1; i >=  start + 2; i--){
        if(inv[i].second < x){
            cur += inv[i].first;
        }else cur += max(inv[i].first,x);
    }
    return cur <= s;
}
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> s;
        for(int i = 0; i < n; i++){
            cin >> inv[i].first >> inv[i].second;
        }
        sort(inv,inv+n);
        int low = inv[n/2].first, hi = 1e9;
        int ans = 0;
        while(low <= hi){
            LL mid = (low + hi + 1) / 2;
             if(check(mid)){
                ans = mid;
                low = mid + 1;
            }else hi = mid - 1;
        }
        cout << ans << endl;
    }
}