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
    int n;
    cin >> n;
    int mx = 0;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        mx = max(mx, x);
    }
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
    }
    LL ans = 0;
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        ans += x;
    }
    cout << ans + (m * mx) << endl;
}