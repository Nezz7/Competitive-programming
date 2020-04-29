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
    int d;
    cin >> d;
    LL ans = 100;
    LL last = 1e18;
    while(d--){
        LL cur = 0;
        cin >> cur;
        if(cur > last)
            ans += min(ans/last,100000LL) * (cur - last);
        last = cur;
    }
    cout << ans;
}