#include <bits/stdc++.h>
#define f first
#define s second
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
    int T;
    cin >> T;
    while (T--){
        int n,m;
        cin >> n;
        int odd = 0, even = 0;
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            if( x % 2) odd++;
            else even ++;
        }
        cin >> m;
        LL ans = 0;
        for(int i = 0; i < m; i++){
            int x;
            cin >> x;
            if(x % 2) ans += odd;
            else ans += even;
        }
        cout << ans << endl;
    }
}