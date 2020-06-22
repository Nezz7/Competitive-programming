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
    int n;
    cin >> n;
    int a[n];
    int s = 0;
    for (int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    vector<int> ans;
    int cur = a[0];
    ans.pb(1);
    for (int i = 1; i < n; i++){
        if (a[0] >= 2 * a[i]){
            cur += a[i];
            ans.pb(i + 1);
        }
    }
    if ( cur > s / 2){
        cout << sz(ans) << endl;
        for (auto cur : ans) cout << cur << ' ';
    }else cout << 0;
}