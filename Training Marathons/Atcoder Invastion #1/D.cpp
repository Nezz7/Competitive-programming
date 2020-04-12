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
LL x[MAXN],y[MAXN];
int main(){
    ios_base::sync_with_stdio (0),cin.tie(0);
    int T;
    cin >> T;
    while (T--){
        int n,m,k;
        cin >> n >> m >> k;
        for(int i = 0; i < k; ++i){
            cin >> x[i] >> y[i];
        }
        LL ans = 0;
        for(int i = 0; i < k; i++){
            int cur = 0;
            LL r = 0, c = 0;
            for(int j = 0; j < k; j++){
                if ( x[j]< x[i] && y[j] < y[i]) cur++,r = max(r,x[j]),c=max(c,y[j]);
            }
            cout << cur <<' '<< x[i] <<' '<< y[i] << ' ' << r * c << " " <<  x[i] * y[i] - r * c<< endl;
            if(cur % 2      ) ans += x[i] * y[i] - r * c;
        }
        cout << ans << " "<< n * m  - ans << endl; 
    }
}