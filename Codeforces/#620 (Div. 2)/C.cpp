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
    int T;
    cin >> T;
    while (T--){
        LL n,m;
        cin >> n >> m;
        LL last = 0;
        LL low = m, high = m;
        bool cond = true;
        for (int i = 0; i < n; i++){
            LL t,l,h;
            cin >> t >> l >> h;
            LL d = t - last;
            last = t;
            low -= d; high += d;
            if (h < low or high < l) cond = false;
            low = max(low,l);
            high = min(h,high);
        }
        if (cond) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}