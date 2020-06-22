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
        LL a, b;
        cin >> a >> b;
        if(a < b) swap(a,b);
        int ans = 0;
        if(a % b != 0){
            cout << -1 << endl;
            continue;
        }
        LL x = a / b;
        while(x > 1){
            if(x % 8 == 0){
                x /= 8;
                ans++;
            }else if(x % 4 == 0){
                x /= 4;
                ans++;
            }else if(x % 2 == 0){
                x/= 2;
                ans++;
            }else{
                ans = -1;
                break;
            }
        }
        cout << ans << endl;
    }
}