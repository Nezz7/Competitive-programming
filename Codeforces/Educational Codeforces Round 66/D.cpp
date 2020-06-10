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
LL a[MAXN], suf[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    suf[n] = 0;
    for(int i = n - 1; i >= 0; i--)
        suf[i] = suf[i + 1] + a[i];
    LL ans = suf[0];
    LL cur = 1;
    vector<LL> v;
    for(int i = 1; i < n; i++){
        v.pb(suf[i]);
    }
    sort(rall(v));
    for(int i = 0; i < k - 1; i++) ans+= v[i];
    cout << ans << endl;
}