
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
int a[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> v;
    for(int i = 0; i < n - 1; i++){
        v.pb(abs(a[i] - a[i + 1]));
    }
    LL ans = -1e18;
    LL cur = 0;
    LL cur1 = 0;
    for(int i = 0; i < sz(v); i++){
        if (i % 2){
            cur +=  v[i];
            cur1 -= v[i];
        }else {
            cur -=  v[i];
            cur1 += v[i];
        }
        ans = max(cur,ans);
        ans = max(cur1,ans);
        if(cur < 0) cur = 0;
        if(cur1 < 0) cur1 = 0;
    }
    cout << ans << endl;
}