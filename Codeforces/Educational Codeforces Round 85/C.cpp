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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        LL a[n],b[n];
        LL sum = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i] >> b[i];
        }
        for(int i = 0; i < n; i++){
            int nxt = i + 1;
            if(nxt == n) nxt = 0;
            if(b[i] < a[nxt]){
                sum += a[nxt] - b[i];
            }
        }
        LL ans = 1e18;
        for(int i = 0; i < n; i++){
            int prev  = i - 1;
            if(prev < 0) prev = n - 1;
            LL x = 0;
            if( b[prev] < a[i] ) x = a[i] - b[prev];
            ans = min(ans, sum + a[i] - x);
        }
        cout << ans << endl;
    }
}